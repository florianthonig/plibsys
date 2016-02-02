/*
 * Copyright (C) 2016 Alexander Saprykin <xelfium@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 */

/**
 * @file perror.h
 * @brief An error report system
 * @author Alexander Saprykin
 *
 * An error report system is used to notify a caller about fatal situations
 * during the library API invocation. Usually the sequence is as following:
 * @code
 * PError *error = NULL;
 * ...
 *
 * if (error != NULL) {
 *         ...
 *         p_error_free (error);
 * }
 * @endcode
 * Note that you should not initialize a new #PError object before passing the
 * pointer into API call. Simply initialize it with zero and check result after.
 * Therefore you need to free memory if error occurred.
 */

#if !defined (__PLIB_H_INSIDE__) && !defined (PLIB_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plib.h> instead."
#endif

#ifndef __PERROR_H__
#define __PERROR_H__

#include <pmacros.h>
#include <ptypes.h>

P_BEGIN_DECLS

/** Opaque data structure for an error object. */
typedef struct _PError PError;

/**
 * @brief Initializes new empty #PError.
 * @return Newly initialized #PError object in case of success,
 * NULL otherwise.
 * @since 0.0.1
 */
P_LIB_API PError *	p_error_new		();

/**
 * @brief Initializes new #PError with data.
 * @param code Error code.
 * @param message Error message.
 * @return Newly initialized #PError object in case of success,
 * NULL otherwise.
 * @since 0.0.1
 */
P_LIB_API PError *	p_error_new_literal	(pint		code,
						 const pchar	*message);

/**
 * @brief Gets error message.
 * @param error #PError object to get message from.
 * @return Error message in case of success, NULL otherwise.
 * @since 0.0.1
 */
P_LIB_API const pchar *	p_error_get_message	(PError		*error);

/**
 * @brief Gets error code.
 * @param error #PError object to get code from.
 * @return Error code in case of success, 0 otherwise.
 * @since 0.0.1
 */
P_LIB_API pint		p_error_get_code	(PError		*error);

/**
 * @brief Creates a copy of a #PError object.
 * @param error #PError object to copy.
 * @return Newly created #PError object in case of success,
 * NULL otherwise.
 * @since 0.0.1
 * @note The caller is responsible to free memory of the created object
 * after the usage.
 */
P_LIB_API PError *	p_error_copy		(PError		*error);

/**
 * @brief Sets error data.
 * @param error #PError object to set data for.
 * @param code Error code.
 * @param message Error message.
 * @since 0.0.1
 */
P_LIB_API void		p_error_set_error	(PError		*error,
						 pint		code,
						 const pchar	*message);

/**
 * @brief Clears error data.
 * @param error #PError object to clear data for.
 * @since 0.0.1
 * @note Error code is reseted to 0.
 */
P_LIB_API void		p_error_clear		(PError		*error);

/**
 * @brief Frees previously initialized error object.
 * @param error #PError object to free.
 * @since 0.0.1
 */
P_LIB_API void		p_error_free		(PError		*error);

P_END_DECLS

#endif /* __PERROR_H__ */
