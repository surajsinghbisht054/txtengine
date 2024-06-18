from setuptools import setup
from Cython.Build import cythonize
from setuptools import Extension

setup(
    name="txtengine",
    version="0.1",
    author="Suraj Singh Bisht",
    author_email="surajsinghbisht054@gmail.com",
    description="TXTEngine is a fast and lightweight Python module for searching and manipulating large text files.",
    long_description=open("README.md").read(),
    ext_modules=cythonize([Extension("txtengine", ["src/txtengine.pyx"])]),
)
