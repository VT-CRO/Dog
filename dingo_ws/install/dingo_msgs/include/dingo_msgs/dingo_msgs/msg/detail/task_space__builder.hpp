// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dingo_msgs:msg/TaskSpace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/task_space.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__TASK_SPACE__BUILDER_HPP_
#define DINGO_MSGS__MSG__DETAIL__TASK_SPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dingo_msgs/msg/detail/task_space__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dingo_msgs
{

namespace msg
{

namespace builder
{

class Init_TaskSpace_rr_foot
{
public:
  explicit Init_TaskSpace_rr_foot(::dingo_msgs::msg::TaskSpace & msg)
  : msg_(msg)
  {}
  ::dingo_msgs::msg::TaskSpace rr_foot(::dingo_msgs::msg::TaskSpace::_rr_foot_type arg)
  {
    msg_.rr_foot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dingo_msgs::msg::TaskSpace msg_;
};

class Init_TaskSpace_rl_foot
{
public:
  explicit Init_TaskSpace_rl_foot(::dingo_msgs::msg::TaskSpace & msg)
  : msg_(msg)
  {}
  Init_TaskSpace_rr_foot rl_foot(::dingo_msgs::msg::TaskSpace::_rl_foot_type arg)
  {
    msg_.rl_foot = std::move(arg);
    return Init_TaskSpace_rr_foot(msg_);
  }

private:
  ::dingo_msgs::msg::TaskSpace msg_;
};

class Init_TaskSpace_fr_foot
{
public:
  explicit Init_TaskSpace_fr_foot(::dingo_msgs::msg::TaskSpace & msg)
  : msg_(msg)
  {}
  Init_TaskSpace_rl_foot fr_foot(::dingo_msgs::msg::TaskSpace::_fr_foot_type arg)
  {
    msg_.fr_foot = std::move(arg);
    return Init_TaskSpace_rl_foot(msg_);
  }

private:
  ::dingo_msgs::msg::TaskSpace msg_;
};

class Init_TaskSpace_fl_foot
{
public:
  explicit Init_TaskSpace_fl_foot(::dingo_msgs::msg::TaskSpace & msg)
  : msg_(msg)
  {}
  Init_TaskSpace_fr_foot fl_foot(::dingo_msgs::msg::TaskSpace::_fl_foot_type arg)
  {
    msg_.fl_foot = std::move(arg);
    return Init_TaskSpace_fr_foot(msg_);
  }

private:
  ::dingo_msgs::msg::TaskSpace msg_;
};

class Init_TaskSpace_header
{
public:
  Init_TaskSpace_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSpace_fl_foot header(::dingo_msgs::msg::TaskSpace::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TaskSpace_fl_foot(msg_);
  }

private:
  ::dingo_msgs::msg::TaskSpace msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dingo_msgs::msg::TaskSpace>()
{
  return dingo_msgs::msg::builder::Init_TaskSpace_header();
}

}  // namespace dingo_msgs

#endif  // DINGO_MSGS__MSG__DETAIL__TASK_SPACE__BUILDER_HPP_
