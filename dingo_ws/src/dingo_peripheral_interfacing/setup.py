from setuptools import setup
import os
from glob import glob

package_name = 'dingo_peripheral_interfacing'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    package_dir={'': 'src'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='youssef',
    maintainer_email='youssefchebil@vt.edu',
    description='Dingo Peripheral Interfacing Package',
    license='MIT',
    entry_points={
        'console_scripts': [
            'dingo_lcd_interfacing = dingo_peripheral_interfacing.dingo_lcd_interfacing:main',
        ],
    },
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/ament_index/resource_index/packages', [ 'resource/' + package_name ]),
    ],

)
# from distutils.core import setup
# from catkin_pkg.python_setup import generate_distutils_setup

# d = generate_distutils_setup(
#     packages=['dingo_peripheral_interfacing'],
#     package_dir={'': 'src'}
# )

# setup(**d)
