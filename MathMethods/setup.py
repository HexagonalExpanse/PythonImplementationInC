from setuptools import setup, Extension

ext = Extension(
    name='MathMethod',                  
    sources=['MathMethod.cpp'],
    language='c++',
)

setup(
    name='MathTools',
    version='1.0',
    ext_modules=[ext],
    py_modules=['MathMethodPy'],
)
