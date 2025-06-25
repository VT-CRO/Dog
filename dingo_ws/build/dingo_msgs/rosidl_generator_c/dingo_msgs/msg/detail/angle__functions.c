// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice
#include "dingo_msgs/msg/detail/angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dingo_msgs__msg__Angle__init(dingo_msgs__msg__Angle * msg)
{
  if (!msg) {
    return false;
  }
  // theta1
  // theta2
  // theta3
  return true;
}

void
dingo_msgs__msg__Angle__fini(dingo_msgs__msg__Angle * msg)
{
  if (!msg) {
    return;
  }
  // theta1
  // theta2
  // theta3
}

bool
dingo_msgs__msg__Angle__are_equal(const dingo_msgs__msg__Angle * lhs, const dingo_msgs__msg__Angle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // theta1
  if (lhs->theta1 != rhs->theta1) {
    return false;
  }
  // theta2
  if (lhs->theta2 != rhs->theta2) {
    return false;
  }
  // theta3
  if (lhs->theta3 != rhs->theta3) {
    return false;
  }
  return true;
}

bool
dingo_msgs__msg__Angle__copy(
  const dingo_msgs__msg__Angle * input,
  dingo_msgs__msg__Angle * output)
{
  if (!input || !output) {
    return false;
  }
  // theta1
  output->theta1 = input->theta1;
  // theta2
  output->theta2 = input->theta2;
  // theta3
  output->theta3 = input->theta3;
  return true;
}

dingo_msgs__msg__Angle *
dingo_msgs__msg__Angle__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__Angle * msg = (dingo_msgs__msg__Angle *)allocator.allocate(sizeof(dingo_msgs__msg__Angle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dingo_msgs__msg__Angle));
  bool success = dingo_msgs__msg__Angle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dingo_msgs__msg__Angle__destroy(dingo_msgs__msg__Angle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dingo_msgs__msg__Angle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dingo_msgs__msg__Angle__Sequence__init(dingo_msgs__msg__Angle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__Angle * data = NULL;

  if (size) {
    data = (dingo_msgs__msg__Angle *)allocator.zero_allocate(size, sizeof(dingo_msgs__msg__Angle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dingo_msgs__msg__Angle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dingo_msgs__msg__Angle__fini(&data[i - 1]);
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
dingo_msgs__msg__Angle__Sequence__fini(dingo_msgs__msg__Angle__Sequence * array)
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
      dingo_msgs__msg__Angle__fini(&array->data[i]);
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

dingo_msgs__msg__Angle__Sequence *
dingo_msgs__msg__Angle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__Angle__Sequence * array = (dingo_msgs__msg__Angle__Sequence *)allocator.allocate(sizeof(dingo_msgs__msg__Angle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dingo_msgs__msg__Angle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dingo_msgs__msg__Angle__Sequence__destroy(dingo_msgs__msg__Angle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dingo_msgs__msg__Angle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dingo_msgs__msg__Angle__Sequence__are_equal(const dingo_msgs__msg__Angle__Sequence * lhs, const dingo_msgs__msg__Angle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dingo_msgs__msg__Angle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dingo_msgs__msg__Angle__Sequence__copy(
  const dingo_msgs__msg__Angle__Sequence * input,
  dingo_msgs__msg__Angle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dingo_msgs__msg__Angle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dingo_msgs__msg__Angle * data =
      (dingo_msgs__msg__Angle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dingo_msgs__msg__Angle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dingo_msgs__msg__Angle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dingo_msgs__msg__Angle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
