from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_msgs', 'dingo_msgs.*')),
)
