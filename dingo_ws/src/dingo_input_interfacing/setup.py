from setuptools import setup

package_name = 'dingo_input_interfacing'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    package_dir={'': 'src'},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='youssef',
    maintainer_email='youssefchebil@vt.edu',
    description='Dingo Input Interfacing Package',
    license='MIT',
    entry_points={
        'console_scripts': [
        ],
    },
    # entry_points={
    #     'console_scripts': [
    #         'input_node = dingo_input_interfacing.input_node:main',
    #     ],
    # },
)

# from distutils.core import setup
# from catkin_pkg.python_setup import generate_distutils_setup

# d = generate_distutils_setup(
#     packages=['dingo_input_interfacing'],
#     package_dir={'': 'src'}
# )

# setup(**d)