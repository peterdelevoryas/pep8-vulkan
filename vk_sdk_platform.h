//
// file: vk_sdk_platform.h
//
/*
 * copyright (c) 2015-2016 the khronos group inc.
 * copyright (c) 2015-2016 valve corporation
 * copyright (c) 2015-2016 lunar_g, inc.
 *
 * licensed under the apache license, version 2.0 (the "License");
 * you may not use this file except in compliance with the license.
 * you may obtain a copy of the license at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 */

#ifndef VK_SDK_PLATFORM_H
#define VK_SDK_PLATFORM_H

#if defined(_WIN32)
#define NOMINMAX
#ifndef __cplusplus
#undef inline
#define inline __inline
#endif // __cplusplus

#if (defined(_MSC_VER) && _MSC_VER < 1900 /*vs2015*/)
// C99:
// microsoft didn't implement C99 in visual studio; but started adding it with
// VS2013.  however, VS2013 still didn't have snprintf().  the following is a
// work-around (note: the _CRT_SECURE_NO_WARNINGS macro must be set in the
// "CMakeLists.txt" file).
// NOTE: this is fixed in visual studio 2015.
#define snprintf _snprintf
#endif

#define strdup _strdup

#endif // _WIN32

// check for noexcept support using clang, with fallback to windows or GCC version numbers
#ifndef NOEXCEPT
#if defined(__clang__)
#if __has_feature(cxx_noexcept)
#define HAS_NOEXCEPT
#endif
#else
#if defined(__GXX_EXPERIMENTAL_CXX0X__) && __GNUC__ * 10 + __GNUC_MINOR__ >= 46
#define HAS_NOEXCEPT
#else
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 190023026 && defined(_HAS_EXCEPTIONS) && _HAS_EXCEPTIONS
#define HAS_NOEXCEPT
#endif
#endif
#endif

#ifdef HAS_NOEXCEPT
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif
#endif

#endif // VK_SDK_PLATFORM_H
