// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dingo_msgs:msg/ElectricalMeasurements.idl
// generated code does not contain a copyright notice
#include "dingo_msgs/msg/detail/electrical_measurements__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dingo_msgs__msg__ElectricalMeasurements__init(dingo_msgs__msg__ElectricalMeasurements * msg)
{
  if (!msg) {
    return false;
  }
  // battery_voltage_level
  // servo_buck_voltage_level
  return true;
}

void
dingo_msgs__msg__ElectricalMeasurements__fini(dingo_msgs__msg__ElectricalMeasurements * msg)
{
  if (!msg) {
    return;
  }
  // battery_voltage_level
  // servo_buck_voltage_level
}

bool
dingo_msgs__msg__ElectricalMeasurements__are_equal(const dingo_msgs__msg__ElectricalMeasurements * lhs, const dingo_msgs__msg__ElectricalMeasurements * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_voltage_level
  if (lhs->battery_voltage_level != rhs->battery_voltage_level) {
    return false;
  }
  // servo_buck_voltage_level
  if (lhs->servo_buck_voltage_level != rhs->servo_buck_voltage_level) {
    return false;
  }
  return true;
}

bool
dingo_msgs__msg__ElectricalMeasurements__copy(
  const dingo_msgs__msg__ElectricalMeasurements * input,
  dingo_msgs__msg__ElectricalMeasurements * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_voltage_level
  output->battery_voltage_level = input->battery_voltage_level;
  // servo_buck_voltage_level
  output->servo_buck_voltage_level = input->servo_buck_voltage_level;
  return true;
}

dingo_msgs__msg__ElectricalMeasurements *
dingo_msgs__msg__ElectricalMeasurements__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__ElectricalMeasurements * msg = (dingo_msgs__msg__ElectricalMeasurements *)allocator.allocate(sizeof(dingo_msgs__msg__ElectricalMeasurements), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dingo_msgs__msg__ElectricalMeasurements));
  bool success = dingo_msgs__msg__ElectricalMeasurements__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dingo_msgs__msg__ElectricalMeasurements__destroy(dingo_msgs__msg__ElectricalMeasurements * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dingo_msgs__msg__ElectricalMeasurements__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dingo_msgs__msg__ElectricalMeasurements__Sequence__init(dingo_msgs__msg__ElectricalMeasurements__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__ElectricalMeasurements * data = NULL;

  if (size) {
    data = (dingo_msgs__msg__ElectricalMeasurements *)allocator.zero_allocate(size, sizeof(dingo_msgs__msg__ElectricalMeasurements), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dingo_msgs__msg__ElectricalMeasurements__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dingo_msgs__msg__ElectricalMeasurements__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dingo_msgs__msg__ElectricalMeasurements__Sequence__fini(dingo_msgs__msg__ElectricalMeasurements__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dingo_msgs__msg__ElectricalMeasurements__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dingo_msgs__msg__ElectricalMeasurements__Sequence *
dingo_msgs__msg__ElectricalMeasurements__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__ElectricalMeasurements__Sequence * array = (dingo_msgs__msg__ElectricalMeasurements__Sequence *)allocator.allocate(sizeof(dingo_msgs__msg__ElectricalMeasurements__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dingo_msgs__msg__ElectricalMeasurements__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dingo_msgs__msg__ElectricalMeasurements__Sequence__destroy(dingo_msgs__msg__ElectricalMeasurements__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dingo_msgs__msg__ElectricalMeasurements__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dingo_msgs__msg__ElectricalMeasurements__Sequence__are_equal(const dingo_msgs__msg__ElectricalMeasurements__Sequence * lhs, const dingo_msgs__msg__ElectricalMeasurements__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dingo_msgs__msg__ElectricalMeasurements__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dingo_msgs__msg__ElectricalMeasurements__Sequence__copy(
  const dingo_msgs__msg__ElectricalMeasurements__Sequence * input,
  dingo_msgs__msg__ElectricalMeasurements__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dingo_msgs__msg__ElectricalMeasurements);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dingo_msgs__msg__ElectricalMeasurements * data =
      (dingo_msgs__msg__ElectricalMeasurements *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dingo_msgs__msg__ElectricalMeasurements__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dingo_msgs__msg__ElectricalMeasurements__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dingo_msgs__msg__ElectricalMeasurements__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
