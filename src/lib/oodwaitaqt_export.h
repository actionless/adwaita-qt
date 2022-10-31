#ifndef OODWAITAQT_EXPORT_H
#define OODWAITAQT_EXPORT_H

#if defined(_WIN32)
#  if defined (oodwaitaqt6priv_EXPORTS) || defined (oodwaitaqtpriv_EXPORTS)
#    define OODWAITAQT_EXPORT __declspec(dllexport)
#  else
#    define OODWAITAQT_EXPORT __declspec(dllimport)
#  endif
#elif defined(__GNUC__)
#    define OODWAITAQT_EXPORT __attribute__((visibility("default")))
#else
#    define OODWAITAQT_EXPORT
#endif

#if defined(_WIN32)
#  if defined (oodwaitaqt6_EXPORTS) || defined (oodwaitaqt_EXPORTS)
#    define OODWAITAQT_MAIN_EXPORT __declspec(dllexport)
#  else
#    define OODWAITAQT_MAIN_EXPORT __declspec(dllimport)
#  endif
#elif defined(__GNUC__)
#    define OODWAITAQT_MAIN_EXPORT __attribute__((visibility("default")))
#else
#    define OODWAITAQT_MAIN_EXPORT
#endif

#ifndef OODWAITAQT_NO_EXPORT
#   define OODWAITAQT_NO_EXPORT __attribute__((visibility("hidden")))
#endif

#ifndef OODWAITAQT_DEPRECATED
#  define OODWAITAQT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef OODWAITAQT_DEPRECATED_EXPORT
#  define OODWAITAQT_DEPRECATED_EXPORT OODWAITAQT_EXPORT OODWAITAQT_DEPRECATED
#endif

#ifndef OODWAITAQT_DEPRECATED_NO_EXPORT
#  define OODWAITAQT_DEPRECATED_NO_EXPORT OODWAITAQT_NO_EXPORT OODWAITAQT_DEPRECATED
#endif

#endif
