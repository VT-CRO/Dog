// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "dingo_msgs/msg/detail/angle__struct.h"
#include "dingo_msgs/msg/detail/angle__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool dingo_msgs__msg__angle__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[28];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("dingo_msgs.msg._angle.Angle", full_classname_dest, 27) == 0);
  }
  dingo_msgs__msg__Angle * ros_message = _ros_message;
  {  // theta1
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta2
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta3
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dingo_msgs__msg__angle__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Angle */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dingo_msgs.msg._angle");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Angle");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dingo_msgs__msg__Angle * ros_message = (dingo_msgs__msg__Angle *)raw_ros_message;
  {  // theta1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
