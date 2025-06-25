from setuptools import setup

package_name = 'dingo_servo_interfacing'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    package_dir={'': 'src'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='youssef',
    maintainer_email='youssefchebil@vt.edu',
    description='Dingo Servo Interfacing Package',
    license='MIT',
    entry_points={
        'console_scripts': [
        ],
    },
    # entry_points={
    #     'console_scripts': [
    #         'servo_node = dingo_servo_interfacing.servo_node:main',
    #     ],
    # },
)

# from distutils.core import setup
# from catkin_pkg.python_setup import generate_distutils_setup

# d = generate_distutils_setup(
#     packages=['dingo_servo_interfacing'],
#     package_dir={'': 'src'}
# )

# setup(**d)