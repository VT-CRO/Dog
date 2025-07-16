// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dingo_msgs:msg/Angle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dingo_msgs/msg/angle.hpp"


#ifndef DINGO_MSGS__MSG__DETAIL__ANGLE__BUILDER_HPP_
#define DINGO_MSGS__MSG__DETAIL__ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dingo_msgs/msg/detail/angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dingo_msgs
{

namespace msg
{

namespace builder
{

class Init_Angle_theta3
{
public:
  explicit Init_Angle_theta3(::dingo_msgs::msg::Angle & msg)
  : msg_(msg)
  {}
  ::dingo_msgs::msg::Angle theta3(::dingo_msgs::msg::Angle::_theta3_type arg)
  {
    msg_.theta3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dingo_msgs::msg::Angle msg_;
};

class Init_Angle_theta2
{
public:
  explicit Init_Angle_theta2(::dingo_msgs::msg::Angle & msg)
  : msg_(msg)
  {}
  Init_Angle_theta3 theta2(::dingo_msgs::msg::Angle::_theta2_type arg)
  {
    msg_.theta2 = std::move(arg);
    return Init_Angle_theta3(msg_);
  }

private:
  ::dingo_msgs::msg::Angle msg_;
};

class Init_Angle_theta1
{
public:
  Init_Angle_theta1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Angle_theta2 theta1(::dingo_msgs::msg::Angle::_theta1_type arg)
  {
    msg_.theta1 = std::move(arg);
    return Init_Angle_theta2(msg_);
  }

private:
  ::dingo_msgs::msg::Angle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dingo_msgs::msg::Angle>()
{
  return dingo_msgs::msg::builder::Init_Angle_theta1();
}

}  // namespace dingo_msgs

#endif  // DINGO_MSGS__MSG__DETAIL__ANGLE__BUILDER_HPP_
