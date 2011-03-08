#if !defined(TEST_VM_HAS_STATIC_MEM_FUN_TEMPLATE_HPP)
#define TEST_VM_HAS_STATIC_MEM_FUN_TEMPLATE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_VARIADIC_MACROS)

#include "test_structs.hpp"
#include <boost/tti/vm_static_mem_fun_template.hpp>
#include <boost/tti/mem_type.hpp>

BOOST_TTI_VM_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(StatFuncTemplate,short,bool,24)
BOOST_TTI_VM_TRAIT_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(TAnother,AnotherFuncTemplate,double,double,long)
BOOST_TTI_VM_HAS_STATIC_MEMBER_FUNCTION_TEMPLATE(YetAnotherFuncTemplate,long,int)

BOOST_TTI_MEMBER_TYPE(AStructType)

#endif //!defined(BOOST_NO_VARIADIC_MACROS)

#endif // TEST_VM_HAS_STATIC_MEM_FUN_TEMPLATE_HPP
