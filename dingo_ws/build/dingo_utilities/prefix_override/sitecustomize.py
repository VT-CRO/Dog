import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/robogames/Desktop/Dog/dingo_ws/install/dingo_utilities'
