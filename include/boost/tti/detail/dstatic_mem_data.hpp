#if !defined(TTI_DETAIL_STATIC_MEM_DATA_HPP)
#define TTI_DETAIL_STATIC_MEM_DATA_HPP

#include <boost/config.hpp>
#include <boost/function_types/is_function.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

#if defined(BOOST_MSVC)

#define TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  template<class T,class Type> \
  struct trait \
    { \
    template<bool,typename U> \
    struct menable_if; \
    \
    template<typename U> \
    struct menable_if<true,U> \
      { \
      typedef U type; \
      }; \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::yes_type check2(V *); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type check2(U); \
    \
    template<typename U,typename V> \
    static typename \
      menable_if \
        < \
        sizeof(check2<U,V>(&U::name))==sizeof(::boost::type_traits::yes_type), \
        ::boost::type_traits::yes_type \
        > \
      ::type \
    has_matching_member(int); \
    \
    template<typename U,typename V> \
    static ::boost::type_traits::no_type has_matching_member(...); \
    \
    template<class U,class V> \
    struct ttc_sd \
      { \
      typedef boost::mpl::bool_<sizeof(has_matching_member<V,U>(0))==sizeof(::boost::type_traits::yes_type)> type; \
      }; \
    \
    typedef typename ttc_sd<Type,T>::type type; \
    \
    BOOST_STATIC_CONSTANT(bool,value=type::value); \
    }; \
/**/

#define TTI_DETAIL_MTFC_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  struct trait \
    { \
    template<class T,class Type> \
    struct apply \
      { \
      template<bool,typename U> \
      struct menable_if; \
      \
      template<typename U> \
      struct menable_if<true,U> \
        { \
        typedef U type; \
        }; \
      \
      template<typename U,typename V> \
      static ::boost::type_traits::yes_type check2(V *); \
      \
      template<typename U,typename V> \
      static ::boost::type_traits::no_type check2(U); \
      \
      template<typename U,typename V> \
      static typename \
        menable_if \
          < \
          sizeof(check2<U,V>(&U::name))==sizeof(::boost::type_traits::yes_type), \
          ::boost::type_traits::yes_type \
          > \
        ::type \
      has_matching_member(int); \
      \
      template<typename U,typename V> \
      static ::boost::type_traits::no_type has_matching_member(...); \
      \
      template<class U,class V> \
      struct ttc_sd \
        { \
        typedef boost::mpl::bool_<sizeof(has_matching_member<V,U>(0))==sizeof(::boost::type_traits::yes_type)> type; \
        }; \
      \
      typedef typename ttc_sd<Type,T>::type type; \
      \
      BOOST_STATIC_CONSTANT(bool,value=type::value); \
      }; \
    }; \
/**/

#else // !defined(BOOST_MSVC)

#if defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  template<class T,class Type> \
  struct trait \
    { \
    template<Type *> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=(!boost::function_types::is_function<Type>::value) && (sizeof(check<T>(0))==sizeof(::boost::type_traits::yes_type))); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#define TTI_DETAIL_MTFC_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  struct trait \
    { \
    template<class T,class Type> \
    struct apply \
      { \
      template<Type *> \
      struct helper; \
      \
      template<class U> \
      static ::boost::type_traits::yes_type check(helper<&U::name> *); \
      \
      template<class U> \
      static ::boost::type_traits::no_type check(...); \
      \
      BOOST_STATIC_CONSTANT(bool,value=(!boost::function_types::is_function<Type>::value) && (sizeof(check<T>(0))==sizeof(::boost::type_traits::yes_type))); \
      \
      typedef boost::mpl::bool_<value> type; \
      }; \
    }; \
/**/

#else // !defined(BOOST_NO_NULLPTR)

#define TTI_DETAIL_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  template<class T,class Type> \
  struct trait \
    { \
    template<Type *> \
    struct helper; \
    \
    template<class U> \
    static ::boost::type_traits::yes_type check(helper<&U::name> *); \
    \
    template<class U> \
    static ::boost::type_traits::no_type check(...); \
    \
    BOOST_STATIC_CONSTANT(bool,value=(!boost::function_types::is_function<Type>::value) && (sizeof(check<T>(nullptr))==sizeof(::boost::type_traits::yes_type))); \
    \
    typedef boost::mpl::bool_<value> type; \
    }; \
/**/

#define TTI_DETAIL_MTFC_TRAIT_HAS_STATIC_MEMBER_DATA(trait,name) \
  struct trait \
    { \
    template<class T,class Type> \
    struct apply \
      { \
      template<Type *> \
      struct helper; \
      \
      template<class U> \
      static ::boost::type_traits::yes_type check(helper<&U::name> *); \
      \
      template<class U> \
      static ::boost::type_traits::no_type check(...); \
      \
      BOOST_STATIC_CONSTANT(bool,value=(!boost::function_types::is_function<Type>::value) && (sizeof(check<T>(nullptr))==sizeof(::boost::type_traits::yes_type))); \
      \
      typedef boost::mpl::bool_<value> type; \
      }; \
    }; \
/**/

#endif // defined(BOOST_NO_NULLPTR)

#endif // defined(BOOST_MSVC)

#endif // TTI_DETAIL_STATIC_MEM_DATA_HPP
