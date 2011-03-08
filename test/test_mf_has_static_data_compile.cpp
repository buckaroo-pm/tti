#include "test_mf_has_static_data.hpp"
#include <boost/mpl/assert.hpp>

int main()
  {
  
  using namespace boost::mpl::placeholders;
  
  // You can always instantiate without compiler errors
  
  boost::tti::mf_has_static_member_data
    <
    boost::tti::has_static_member_data_SomeStaticData<_,_>,
    boost::mpl::identity<AnotherType>,
    boost::mpl::identity<double>
    > aVar;
  
  // Compile time asserts
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_data
                      <
                      boost::tti::has_static_member_data_DSMember<_,_>,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  BOOST_MPL_ASSERT((boost::tti::mf_has_static_member_data
                      <
                      boost::tti::mtfc_has_static_member_data_DSMember,
                      boost::mpl::identity<AType>,
                      boost::mpl::identity<short>
                      >
                  ));
  
  return 0;

  }
