# -*- coding: utf-8 -*-

import sys
from glob import glob
from setuptools import setup, Extension
from distutils.command.build import build


with open('README.md') as f:
    long_description = f.read()

include_dirs = ['src']
libraries = ['speexdsp', 'stdc++']
define_macros = []
extra_compile_args = []

sources = (
    glob('src/echo_canceller.cpp') +
    ['src/speexdsp.i']
)

swig_opts = (
    ['-c++'] +
    ['-I' + h for h in include_dirs]
)


setup(
    name='speexdsp',
    version='0.1.0',
    description='Python bindings of speexdsp library',
    long_description=long_description,
    long_description_content_type='text/markdown',
    author='Yihui Xiong',
    author_email='yihui.xiong@hotmail.com',
    maintainer='Yihui Xiong',
    maintainer_email='yihui.xiong@hotmail.com',
    url='https://github.com/xiongyihui/speexdsp-python',
    download_url='https://pypi.python.org/pypi/speexdsp',
    packages=['speexdsp'],
    ext_modules=[
        Extension(
            name='speexdsp._speexdsp',
            sources=sources,
            swig_opts=swig_opts,
            include_dirs=include_dirs,
            libraries=libraries,
            define_macros=define_macros,
            extra_compile_args=extra_compile_args
        )
    ],
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'License :: OSI Approved :: BSD License',
        'Operating System :: POSIX :: Linux',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.6',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.2',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: C++'
    ],
    license='BSD',
    keywords=['speexdsp', 'acoustic echo cancellation'],
    platforms=['Linux'],
    package_dir={
        'speexdsp': 'src'
    }
)
