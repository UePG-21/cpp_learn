/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/31/21
 */
#include <string>
#include "Option.hpp"

using namespace std;

Option::Option() {}

Option::Option(const OptionData& source) : data(source) {}

Option::Option(const Option& source) : data(source.data) {}

Option::~Option() {}
