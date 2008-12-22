/*
 * CoveredCalc
 *
 * Copyright (c) 2004-2008 CoveredCalc Project Contributors
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*!
	@file		StringID.h
	@brief		Definition of string ID
	@author		ICHIMIYA Hironori (Hiron)
	@date		2007.01.07 Created
*/

#ifdef IMPLEMENT_STRINGID_CONVERSION
#undef _STRINGID_H_
#endif

#ifndef _STRINGID_H_
#define _STRINGID_H_

ConstUTF8Str ConvertStringID(SInt32 id);

#ifdef IMPLEMENT_STRINGID_CONVERSION
	#define STRING_ID(name, num)	case num: return TypeConv::AsUTF8(#name);
	ConstUTF8Str ConvertStringID(SInt32 id)
	{
		switch (id)
		{
#else
	#define STRING_ID(name, num)	name = num,
	enum
	{
#endif

	// menu items
	STRING_ID(IDS_MENU_COVER_BROWSER,					4000)
	STRING_ID(IDS_MENU_RADIX,							4001)
	STRING_ID(IDS_MENU_RADIX_HEX,						4002)
	STRING_ID(IDS_MENU_RADIX_DECIMAL,					4003)
	STRING_ID(IDS_MENU_RADIX_OCTAL,						4004)
	STRING_ID(IDS_MENU_RADIX_BINARY,					4005)
	STRING_ID(IDS_MENU_MAIN_ALWAYS_ON_TOP,				4006)
	STRING_ID(IDS_MENU_MAIN_LOCK_POS,					4007)
	STRING_ID(IDS_MENU_PREFERENCES,						4008)
	STRING_ID(IDS_MENU_MAIN_ABOUT_COVER,				4009)
	STRING_ID(IDS_MENU_ABOUT,							4010)
	STRING_ID(IDS_MENU_MAIN_MINIMIZE,					4011)
	STRING_ID(IDS_MENU_MAIN_CLOSE,						4012)

	// About dialog
	STRING_ID(IDS_ABOUT_TITLE,							5000)
	STRING_ID(IDS_ABOUT_OK,								5001)

	// Cover Browser
	STRING_ID(IDS_COVER_BROWSER_TITLE,					5100)
	STRING_ID(IDS_COVER_BROWSER_SELECT_COVER,			5101)
	STRING_ID(IDS_COVER_BROWSER_COLUMN_NAME,			5102)
	STRING_ID(IDS_COVER_BROWSER_COLUMN_DESCRIPTION, 	5103)
	STRING_ID(IDS_COVER_BROWSER_RELOAD, 				5104)
	STRING_ID(IDS_COVER_BROWSER_APPLY,					5105)
	STRING_ID(IDS_COVER_BROWSER_CLOSE,					5106)

	// About Current Cover
	STRING_ID(IDS_ABOUT_COVER_TITLE,					5200)
	STRING_ID(IDS_ABOUT_COVER_NAME,						5201)
	STRING_ID(IDS_ABOUT_COVER_DESCRIPTION,				5202)
	STRING_ID(IDS_ABOUT_COVER_ABOUT,					5203)
	STRING_ID(IDS_ABOUT_COVER_OK,						5204)

	// Preferences dialog
	STRING_ID(IDS_PREFERENCES_TITLE,					5300)
	STRING_ID(IDS_PREFERENCES_GROUP_TRANSPARENCY,		5301)
	STRING_ID(IDS_PREFERENCES_OPACITY,					5302)
	STRING_ID(IDS_PREFERENCES_TRANSPARENT,				5303)
	STRING_ID(IDS_PREFERENCES_OPAQUE,					5304)
	STRING_ID(IDS_PREFERENCES_SMOTHING,					5305)
	STRING_ID(IDS_PREFERENCES_LOW,						5306)
	STRING_ID(IDS_PREFERENCES_HIGH,						5307)
	STRING_ID(IDS_PREFERENCES_TRANSPARENCY_MESSAGE,		5308)
	STRING_ID(IDS_PREFERENCES_GROUP_LANGUAGE,			5309)
	STRING_ID(IDS_PREFERENCES_LANGUAGE,					5310)
	STRING_ID(IDS_PREFERENCES_LANGUAGE_MESSAGE,			5311)
	STRING_ID(IDS_PREFERENCES_GROUP_KEYMAP,				5312)
	STRING_ID(IDS_PREFERENCES_KEYMAP,					5313)
	STRING_ID(IDS_PREFERENCES_EDIT_KEYMAP,				5314)
	STRING_ID(IDS_PREFERENCES_DUPLICATE_KEYMAP,			5315)
	STRING_ID(IDS_PREFERENCES_DELETE_KEYMAP,			5316)
	STRING_ID(IDS_PREFERENCES_OK,						5317)
	STRING_ID(IDS_PREFERENCES_CANCEL,					5318)

	// Edit keymap dialog
	STRING_ID(IDS_EDIT_KEYMAP_TITLE,					5400)
	STRING_ID(IDS_EDIT_KEYMAP_NAME, 					5401)
	STRING_ID(IDS_EDIT_KEYMAP_GROUP_FUNCTION,			5402)
	STRING_ID(IDS_EDIT_KEYMAP_FUNCTION, 				5403)
	STRING_ID(IDS_EDIT_KEYMAP_CURRENT_KEY,				5404)
	STRING_ID(IDS_EDIT_KEYMAP_REMOVE,					5405)
	STRING_ID(IDS_EDIT_KEYMAP_GROUP_KEY,				5406)
	STRING_ID(IDS_EDIT_KEYMAP_KEY,						5407)
	STRING_ID(IDS_EDIT_KEYMAP_ASSIGNED_FUNCTION,		5408)
	STRING_ID(IDS_EDIT_KEYMAP_ASSIGN,					5409)
	STRING_ID(IDS_EDIT_KEYMAP_OK,						5410)
	STRING_ID(IDS_EDIT_KEYMAP_CANCEL,					5411)

	// messages
	STRING_ID(IDS_APPNAME,								10000)
	STRING_ID(IDS_KEYMAPPINGS_COPY, 					10003)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_0,				10100)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_1,				10101)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_2,				10102)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_3,				10103)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_4,				10104)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_5,				10105)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_6,				10106)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_7,				10107)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_8,				10108)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_9,				10109)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_A,				10110)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_B,				10111)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_C,				10112)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_D,				10113)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_E,				10114)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_F,				10115)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_POINT,			10116)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_CLEAR,			10117)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_BS,				10118)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_EQUAL,			10119)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_PLUS, 			10120)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_MINUS,			10121)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_TIMES,			10122)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_DIV,				10123)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_NEGATE,			10124)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_HEX,				10125)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_DEC,				10126)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_OCT,				10127)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_BIN,				10128)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_MINIMIZE, 		10129)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_CLOSE,			10130)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_COVER_BROWSER,	10131)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_ALWAYS_ON_TOP,	10132)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_LOCK_POS, 		10133)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_PREFERENCES,		10134)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_ABOUT_COVER,		10135)
	STRING_ID(IDS_MAIN_WINDOW_KEYFUNC_ABOUT,			10136)
	STRING_ID(IDS_QMSG_EDITED_KEYMAP_DISCARDING,		10985)
	STRING_ID(IDS_EMSG_EMPTY_KEYMAP_NAME,				10986)
	STRING_ID(IDS_EMSG_DELETE_KEYMAPPINGS_IN_USE,		10987)
	STRING_ID(IDS_QMSG_DELETE_KEYMAPPINGS,				10988)
	STRING_ID(IDS_EMSG_INVALID_KEYMAPPINGS, 			10989)
	STRING_ID(IDS_EMSG_GET_KEYMAPPINGS, 				10990)
	STRING_ID(IDS_EMSG_LOAD_KEYMAPPINGS,				10991)
	STRING_ID(IDS_EMSG_INVALID_LANGUAGE,				10992)
	STRING_ID(IDS_EMSG_GET_LANGUAGE,					10993)
	STRING_ID(IDS_EMSG_CREATE_COVER_BROWSER,			10994)
	STRING_ID(IDS_EMSG_LOAD_SETTING,					10995)
	STRING_ID(IDS_EMSG_READY_DEFAULT_SETTING_FILE,		10996)
	STRING_ID(IDS_EMSG_CREATE_MAIN_WINDOW,				10997)
	STRING_ID(IDS_EMSG_SAVE_SETTING,					10998)
	STRING_ID(IDS_EMSG_GENERIC, 						10999)
	STRING_ID(IDS_EMSG_XML_LINE_COLUMN, 				11000)
	STRING_ID(IDS_EMSG_XML_PARSE,						11001)
	STRING_ID(IDS_EMSG_NO_MATCH_START_TAG,				11002)
	STRING_ID(IDS_EMSG_INVALID_PARENT_ENTITY,			11003)
	STRING_ID(IDS_EMSG_MISSING_ATTRIBUTE,				11004)
	STRING_ID(IDS_EMSG_UNKNOWN_TAG, 					11005)
	STRING_ID(IDS_EMSG_COVERDEF_PARSE,					11100)
	STRING_ID(IDS_EMSG_UNKNOWN_ID,						11101)
	STRING_ID(IDS_EMSG_UNKNOWN_CLASS,					11102)
	STRING_ID(IDS_EMSG_UNKNOWN_TYPE,					11103)
	STRING_ID(IDS_EMSG_VALIDATION_FAILED,				11104)
	STRING_ID(IDS_EMSG_COLOR_STRING_NOT_UNDERSTOOD, 	11105)
	STRING_ID(IDS_EMSG_UNSUPPORTED_COVERDEF_VERSION,	11106)
	STRING_ID(IDS_EMSG_INVALID_COVERDEF,				11107)
	STRING_ID(IDS_EMSG_COLOR_CODED_SKIN,				11200)
	STRING_ID(IDS_EMSG_INIT_SKIN,						11201)
	STRING_ID(IDS_EMSG_FILE_OPERATION,					11300)
	STRING_ID(IDS_EMSG_FILE_FILENAME,					11301)
	STRING_ID(IDS_EMSG_FILE_ACCESS_DENIED,				11302)
	STRING_ID(IDS_EMSG_FILE_DEVICE_FULL,				11303)
	STRING_ID(IDS_EMSG_FILE_ALREADY_EXISTS, 			11304)
	STRING_ID(IDS_EMSG_FILE_NOT_FOUND,					11305)
	STRING_ID(IDS_EMSG_FILE_IO_ERROR,					11306)
	STRING_ID(IDS_EMSG_FILE_SHARING_VIOLATION,			11307)
	STRING_ID(IDS_EMSG_DIBFILE_LOAD,					11400)
	STRING_ID(IDS_EMSG_DIBFILE_BROKEN_FILE, 			11401)
	STRING_ID(IDS_EMSG_DIBFILE_UNKNOWN_FORMAT,			11402)
	STRING_ID(IDS_EMSG_MEMORY,							11500)
	STRING_ID(IDS_EMSG_PATH_OPERATION,					11600)
	STRING_ID(IDS_EMSG_PATH_MAKE_RELATIVE,				11601)
	STRING_ID(IDS_EMSG_UI_CONTROL,						11700)
	STRING_ID(IDS_EMSG_UI_SHOW_MENU,					11701)
	STRING_ID(IDS_EMSG_UI_SHOW_DIALOG,					11702)
	STRING_ID(IDS_EMSG_LANG_VALIDATION_FAILED,			11800)
	STRING_ID(IDS_EMSG_LANG_STRING_NOT_DEFINED, 		11801)
	STRING_ID(IDS_EMSG_DIALOG_LAYOUT_COMPUTE,			11900)
	STRING_ID(IDS_EMSG_DIALOG_LAYOUT_NOT_FOUND,			11901)
	STRING_ID(IDS_EMSG_DIALOG_LAYOUT_CIRCULAR_REF,		11902)
	
	STRING_ID(IDS_EMSG_LOAD_COMMANDLINE_LANGFILE,		19000)
	STRING_ID(IDS_EMSG_LOAD_SETTING_LANGFILE,			19001)
	STRING_ID(IDS_EMSG_LOAD_DEFAULT_LANGFILE,			19002)


#undef STRING_ID
#ifdef IMPLEMENT_STRINGID_CONVERSION
		default:
			throw new XMLLangFileExceptions::InvalidStringID(id);
		}
	}
#else
	};
#endif

#endif // _STRINGID_H_
