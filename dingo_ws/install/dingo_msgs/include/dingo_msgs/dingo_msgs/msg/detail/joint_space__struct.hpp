// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dingo_msgs:msg/JointSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/joint_space.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__STRUCT_HPP_
#define DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'fl_foot'
// Member 'fr_foot'
// Member 'rl_foot'
// Member 'rr_foot'
#include "dingo_msgs/msg/detail/angle__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dingo_msgs__msg__JointSpace __attribute__((deprecated))
#else
# define DEPRECATED__dingo_msgs__msg__JointSpace __declspec(deprecated)
#endif

namespace dingo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointSpace_
{
  using Type = JointSpace_<ContainerAllocator>;

  explicit JointSpace_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    fl_foot(_init),
    fr_foot(_init),
    rl_foot(_init),
    rr_foot(_init)
  {
    (void)_init;
  }

  explicit JointSpace_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    fl_foot(_alloc, _init),
    fr_foot(_alloc, _init),
    rl_foot(_alloc, _init),
    rr_foot(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _fl_foot_type =
    dingo_msgs::msg::Angle_<ContainerAllocator>;
  _fl_foot_type fl_foot;
  using _fr_foot_type =
    dingo_msgs::msg::Angle_<ContainerAllocator>;
  _fr_foot_type fr_foot;
  using _rl_foot_type =
    dingo_msgs::msg::Angle_<ContainerAllocator>;
  _rl_foot_type rl_foot;
  using _rr_foot_type =
    dingo_msgs::msg::Angle_<ContainerAllocator>;
  _rr_foot_type rr_foot;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__fl_foot(
    const dingo_msgs::msg::Angle_<ContainerAllocator> & _arg)
  {
    this->fl_foot = _arg;
    return *this;
  }
  Type & set__fr_foot(
    const dingo_msgs::msg::Angle_<ContainerAllocator> & _arg)
  {
    this->fr_foot = _arg;
    return *this;
  }
  Type & set__rl_foot(
    const dingo_msgs::msg::Angle_<ContainerAllocator> & _arg)
  {
    this->rl_foot = _arg;
    return *this;
  }
  Type & set__rr_foot(
    const dingo_msgs::msg::Angle_<ContainerAllocator> & _arg)
  {
    this->rr_foot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dingo_msgs::msg::JointSpace_<ContainerAllocator> *;
  using ConstRawPtr =
    const dingo_msgs::msg::JointSpace_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::JointSpace_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dingo_msgs::msg::JointSpace_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dingo_msgs__msg__JointSpace
    std::shared_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dingo_msgs__msg__JointSpace
    std::shared_ptr<dingo_msgs::msg::JointSpace_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointSpace_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->fl_foot != other.fl_foot) {
      return false;
    }
    if (this->fr_foot != other.fr_foot) {
      return false;
    }
    if (this->rl_foot != other.rl_foot) {
      return false;
    }
    if (this->rr_foot != other.rr_foot) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointSpace_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointSpace_

// alias to use template instance with default allocator
using JointSpace =
  dingo_msgs::msg::JointSpace_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dingo_msgs

#endif  // DINGO_MSGS__MSG__DETAIL__JOINT_SPACE__STRUCT_HPP_
