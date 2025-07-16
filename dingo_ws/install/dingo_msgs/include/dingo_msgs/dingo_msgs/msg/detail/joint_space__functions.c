// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dingo_msgs:msg/JointSpace.idl
// generated code does not contain a copyright notice
#include "dingo_msgs/msg/detail/joint_space__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `fl_foot`
// Member `fr_foot`
// Member `rl_foot`
// Member `rr_foot`
#include "dingo_msgs/msg/detail/angle__functions.h"

bool
dingo_msgs__msg__JointSpace__init(dingo_msgs__msg__JointSpace * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dingo_msgs__msg__JointSpace__fini(msg);
    return false;
  }
  // fl_foot
  if (!dingo_msgs__msg__Angle__init(&msg->fl_foot)) {
    dingo_msgs__msg__JointSpace__fini(msg);
    return false;
  }
  // fr_foot
  if (!dingo_msgs__msg__Angle__init(&msg->fr_foot)) {
    dingo_msgs__msg__JointSpace__fini(msg);
    return false;
  }
  // rl_foot
  if (!dingo_msgs__msg__Angle__init(&msg->rl_foot)) {
    dingo_msgs__msg__JointSpace__fini(msg);
    return false;
  }
  // rr_foot
  if (!dingo_msgs__msg__Angle__init(&msg->rr_foot)) {
    dingo_msgs__msg__JointSpace__fini(msg);
    return false;
  }
  return true;
}

void
dingo_msgs__msg__JointSpace__fini(dingo_msgs__msg__JointSpace * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // fl_foot
  dingo_msgs__msg__Angle__fini(&msg->fl_foot);
  // fr_foot
  dingo_msgs__msg__Angle__fini(&msg->fr_foot);
  // rl_foot
  dingo_msgs__msg__Angle__fini(&msg->rl_foot);
  // rr_foot
  dingo_msgs__msg__Angle__fini(&msg->rr_foot);
}

bool
dingo_msgs__msg__JointSpace__are_equal(const dingo_msgs__msg__JointSpace * lhs, const dingo_msgs__msg__JointSpace * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // fl_foot
  if (!dingo_msgs__msg__Angle__are_equal(
      &(lhs->fl_foot), &(rhs->fl_foot)))
  {
    return false;
  }
  // fr_foot
  if (!dingo_msgs__msg__Angle__are_equal(
      &(lhs->fr_foot), &(rhs->fr_foot)))
  {
    return false;
  }
  // rl_foot
  if (!dingo_msgs__msg__Angle__are_equal(
      &(lhs->rl_foot), &(rhs->rl_foot)))
  {
    return false;
  }
  // rr_foot
  if (!dingo_msgs__msg__Angle__are_equal(
      &(lhs->rr_foot), &(rhs->rr_foot)))
  {
    return false;
  }
  return true;
}

bool
dingo_msgs__msg__JointSpace__copy(
  const dingo_msgs__msg__JointSpace * input,
  dingo_msgs__msg__JointSpace * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // fl_foot
  if (!dingo_msgs__msg__Angle__copy(
      &(input->fl_foot), &(output->fl_foot)))
  {
    return false;
  }
  // fr_foot
  if (!dingo_msgs__msg__Angle__copy(
      &(input->fr_foot), &(output->fr_foot)))
  {
    return false;
  }
  // rl_foot
  if (!dingo_msgs__msg__Angle__copy(
      &(input->rl_foot), &(output->rl_foot)))
  {
    return false;
  }
  // rr_foot
  if (!dingo_msgs__msg__Angle__copy(
      &(input->rr_foot), &(output->rr_foot)))
  {
    return false;
  }
  return true;
}

dingo_msgs__msg__JointSpace *
dingo_msgs__msg__JointSpace__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__JointSpace * msg = (dingo_msgs__msg__JointSpace *)allocator.allocate(sizeof(dingo_msgs__msg__JointSpace), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dingo_msgs__msg__JointSpace));
  bool success = dingo_msgs__msg__JointSpace__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dingo_msgs__msg__JointSpace__destroy(dingo_msgs__msg__JointSpace * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dingo_msgs__msg__JointSpace__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dingo_msgs__msg__JointSpace__Sequence__init(dingo_msgs__msg__JointSpace__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__JointSpace * data = NULL;

  if (size) {
    data = (dingo_msgs__msg__JointSpace *)allocator.zero_allocate(size, sizeof(dingo_msgs__msg__JointSpace), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dingo_msgs__msg__JointSpace__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dingo_msgs__msg__JointSpace__fini(&data[i - 1]);
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
dingo_msgs__msg__JointSpace__Sequence__fini(dingo_msgs__msg__JointSpace__Sequence * array)
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
      dingo_msgs__msg__JointSpace__fini(&array->data[i]);
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

dingo_msgs__msg__JointSpace__Sequence *
dingo_msgs__msg__JointSpace__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dingo_msgs__msg__JointSpace__Sequence * array = (dingo_msgs__msg__JointSpace__Sequence *)allocator.allocate(sizeof(dingo_msgs__msg__JointSpace__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dingo_msgs__msg__JointSpace__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dingo_msgs__msg__JointSpace__Sequence__destroy(dingo_msgs__msg__JointSpace__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dingo_msgs__msg__JointSpace__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dingo_msgs__msg__JointSpace__Sequence__are_equal(const dingo_msgs__msg__JointSpace__Sequence * lhs, const dingo_msgs__msg__JointSpace__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dingo_msgs__msg__JointSpace__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dingo_msgs__msg__JointSpace__Sequence__copy(
  const dingo_msgs__msg__JointSpace__Sequence * input,
  dingo_msgs__msg__JointSpace__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dingo_msgs__msg__JointSpace);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dingo_msgs__msg__JointSpace * data =
      (dingo_msgs__msg__JointSpace *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dingo_msgs__msg__JointSpace__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dingo_msgs__msg__JointSpace__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dingo_msgs__msg__JointSpace__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
