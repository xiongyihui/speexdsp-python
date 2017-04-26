
#ifndef __ECHO_CANCELLER_H__
#define __ECHO_CANCELLER_H__

#include <string>
#include <stdint.h>

class EchoCanceller
{
public:
    static EchoCanceller* create(int frame_size=256, int filter_length=2048, int sample_rate=16000, int mics=1, int speakers=1);

    virtual std::string process(const std::string& near, const std::string& far) = 0;

    virtual ~EchoCanceller() {}
};


#endif // __ECHO_CANCELLER_H__
