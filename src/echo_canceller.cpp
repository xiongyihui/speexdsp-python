
#include <stdint.h>

#include "echo_canceller.h"

#include "speex/speex_echo.h"
#include "speex/speex_preprocess.h"


class EchoCancellerImpl : public EchoCanceller
{
public:
    EchoCancellerImpl(int frame_size=256, int filter_length=2048, int sample_rate=16000, int mics=1, int speakers=1);

    ~EchoCancellerImpl();

    std::string process(const std::string& near, const std::string& far);

private:
    SpeexEchoState *st;
    // SpeexPreprocessState *den;

    int16_t *e;
    int frames;
};


EchoCanceller* EchoCanceller::create(int frame_size, int filter_length, int sample_rate, int mics, int speakers)
{
    return new EchoCancellerImpl(frame_size, filter_length, sample_rate, mics, speakers);
}



EchoCancellerImpl::EchoCancellerImpl(int frame_size, int filter_length, int sample_rate, int mics, int speakers)
{
    st = speex_echo_state_init_mc(frame_size, filter_length, mics, speakers);
    speex_echo_ctl(st, SPEEX_ECHO_SET_SAMPLING_RATE, &sample_rate);

    // den = speex_preprocess_state_init(frame_size, sample_rate);
    // speex_preprocess_ctl(den, SPEEX_PREPROCESS_SET_ECHO_STATE, st);

    frames = frame_size * mics;
    e = new int16_t[frames];
}

EchoCancellerImpl::~EchoCancellerImpl()
{
    speex_echo_state_destroy(st);

    // speex_preprocess_state_destroy(den);

    delete e;
}

std::string EchoCancellerImpl::process(const std::string& near, const std::string& far)
{
    const int16_t *y = (const int16_t *)(near.data());
    const int16_t *x = (const int16_t *)(far.data());

    // e = y - filter(x)
    speex_echo_cancellation(st, y, x, e);

    // speex_preprocess_run(den, e);

    return std::string((const char *)e, frames * sizeof(int16_t));
}

