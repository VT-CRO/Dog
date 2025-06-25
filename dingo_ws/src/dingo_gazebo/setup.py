from setuptools import setup
import os
from glob import glob

package_name = 'dingo_gazebo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    package_dir={'': 'src'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='youssef',
    maintainer_email='youssefchebil@vt.edu',
    description='Dingo Gazebo Package',
    license='MIT',
    entry_points={
        'console_scripts': [
        ],
    },
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/worlds', glob('worlds/*')),   # ✅ if you have a world folder
        ('share/' + package_name + '/config', glob('config/*.yaml')),  # ✅ THIS IS THE IMPORTANT FIX
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
    ],
)
