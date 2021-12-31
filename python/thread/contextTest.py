#!/usr/bin/env python2.7
import contextlib
import time


@contextlib.contextmanager
def timeit(title):
    print('1...')
    start = time.time()
    yield
    print('2...')
    end = time.time()
    usedTime = (end - start) * 1000
    print('Use time %d ms' % usedTime)


with timeit(1):
    print('3...')
    time.sleep(1)

#with timeit(2):
    #print('4...')
    #time.sleep(2)

