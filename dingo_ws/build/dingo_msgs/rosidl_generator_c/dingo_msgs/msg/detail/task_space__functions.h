// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dingo_msgs:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/task_space.h"


#ifndef DINGO_MSGS__MSG__DETAIL__TASK_SPACE__FUNCTIONS_H_
#define DINGO_MSGS__MSG__DETAIL__TASK_SPACE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "dingo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "dingo_msgs/msg/detail/task_space__struct.h"

/// Initialize msg/TaskSpace message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dingo_msgs__msg__TaskSpace
 * )) before or use
 * dingo_msgs__msg__TaskSpace__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__init(dingo_msgs__msg__TaskSpace * msg);

/// Finalize msg/TaskSpace message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
void
dingo_msgs__msg__TaskSpace__fini(dingo_msgs__msg__TaskSpace * msg);

/// Create msg/TaskSpace message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dingo_msgs__msg__TaskSpace__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
dingo_msgs__msg__TaskSpace *
dingo_msgs__msg__TaskSpace__create(void);

/// Destroy msg/TaskSpace message.
/**
 * It calls
 * dingo_msgs__msg__TaskSpace__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
void
dingo_msgs__msg__TaskSpace__destroy(dingo_msgs__msg__TaskSpace * msg);

/// Check for msg/TaskSpace message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__are_equal(const dingo_msgs__msg__TaskSpace * lhs, const dingo_msgs__msg__TaskSpace * rhs);

/// Copy a msg/TaskSpace message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__copy(
  const dingo_msgs__msg__TaskSpace * input,
  dingo_msgs__msg__TaskSpace * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_type_hash_t *
dingo_msgs__msg__TaskSpace__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_runtime_c__type_description__TypeDescription *
dingo_msgs__msg__TaskSpace__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_runtime_c__type_description__TypeSource *
dingo_msgs__msg__TaskSpace__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
dingo_msgs__msg__TaskSpace__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/TaskSpace messages.
/**
 * It allocates the memory for the number of elements and calls
 * dingo_msgs__msg__TaskSpace__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__Sequence__init(dingo_msgs__msg__TaskSpace__Sequence * array, size_t size);

/// Finalize array of msg/TaskSpace messages.
/**
 * It calls
 * dingo_msgs__msg__TaskSpace__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
void
dingo_msgs__msg__TaskSpace__Sequence__fini(dingo_msgs__msg__TaskSpace__Sequence * array);

/// Create array of msg/TaskSpace messages.
/**
 * It allocates the memory for the array and calls
 * dingo_msgs__msg__TaskSpace__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
dingo_msgs__msg__TaskSpace__Sequence *
dingo_msgs__msg__TaskSpace__Sequence__create(size_t size);

/// Destroy array of msg/TaskSpace messages.
/**
 * It calls
 * dingo_msgs__msg__TaskSpace__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
void
dingo_msgs__msg__TaskSpace__Sequence__destroy(dingo_msgs__msg__TaskSpace__Sequence * array);

/// Check for msg/TaskSpace message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__Sequence__are_equal(const dingo_msgs__msg__TaskSpace__Sequence * lhs, const dingo_msgs__msg__TaskSpace__Sequence * rhs);

/// Copy an array of msg/TaskSpace messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dingo_msgs
bool
dingo_msgs__msg__TaskSpace__Sequence__copy(
  const dingo_msgs__msg__TaskSpace__Sequence * input,
  dingo_msgs__msg__TaskSpace__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DINGO_MSGS__MSG__DETAIL__TASK_SPACE__FUNCTIONS_H_
