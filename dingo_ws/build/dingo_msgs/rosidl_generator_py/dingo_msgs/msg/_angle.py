# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dingo_msgs:msg/Angle.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Angle(type):
    """Metaclass of message 'Angle'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('dingo_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dingo_msgs.msg.Angle')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__angle
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__angle
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__angle
            cls._TYPE_SUPPORT = module.type_support_msg__msg__angle
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__angle

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Angle(metaclass=Metaclass_Angle):
    """Message class 'Angle'."""

    __slots__ = [
        '_theta1',
        '_theta2',
        '_theta3',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'theta1': 'float',
        'theta2': 'float',
        'theta3': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.theta1 = kwargs.get('theta1', float())
        self.theta2 = kwargs.get('theta2', float())
        self.theta3 = kwargs.get('theta3', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.theta1 != other.theta1:
            return False
        if self.theta2 != other.theta2:
            return False
        if self.theta3 != other.theta3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def theta1(self):
        """Message field 'theta1'."""
        return self._theta1

    @theta1.setter
    def theta1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'theta1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'theta1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._theta1 = value

    @builtins.property
    def theta2(self):
        """Message field 'theta2'."""
        return self._theta2

    @theta2.setter
    def theta2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'theta2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'theta2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._theta2 = value

    @builtins.property
    def theta3(self):
        """Message field 'theta3'."""
        return self._theta3

    @theta3.setter
    def theta3(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'theta3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'theta3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._theta3 = value
