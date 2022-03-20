import unittest
import time, functools
from max_sum import getMaxSumSection

def metric(fn):
    @functools.wraps(fn)
    def wrapper(*args,**kw):
        start = time.perf_counter()
        ret = fn(*args,**kw)
        end = time.perf_counter()
        print('{} took {} ms'.format(fn.__name__, (end - start) * 1000))
        return ret

    return wrapper

class TestMaxSumMethods(unittest.TestCase):
    def __init__(self, methodName: str = ...) -> None:
        super().__init__(methodName=methodName)
        self.dataset=[[ i for i in range(10000)] for i in range(1000)]
        
    def setUp(self):
        #self.dataset=[[ i for i in range(10000)] for i in range(1000)]
        pass
    @metric
    def test_getMaxSumSection(self):
        self.assertEqual('foo'.upper(), 'FOO')
        for data in self.dataset:
            getMaxSumSection(data)

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()