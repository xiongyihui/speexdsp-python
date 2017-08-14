
import wave
import sys
from speexdsp import EchoCanceller
import pytest


def test_echo_canceller():
    frames = 64
    filter_length = 256
    echo_canceller = EchoCanceller.create(64, 256, 16000)

    chunk = '\0\0' * frames
    for _ in range(16):
        out = echo_canceller.process(chunk, chunk)
