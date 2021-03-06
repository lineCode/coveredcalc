/*
 * CoveredCalc
 *
 * Copyright (c) 2004-2009 CoveredCalc Project Contributors
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
	@file		CoveredCalcAppBase.h
	@brief		Definition of CoveredCalcAppBase class
	@author		ICHIMIYA Hironori (Hiron)
	@date		2004.02.11 created
*/

#ifndef _COVEREDCALCAPPBASE_H_
#define _COVEREDCALCAPPBASE_H_

#include <vector>
#include "CoveredCalcApp.h"
#include "CoverManager.h"
#include "AppSettings.h"
#include "CoverChangeEventHandler.h"
#include "ExceptionMessageGenerator.h"
#include "CommandLineParam.h"
#include "LangFileInfo.h"
#include "KeyMappingManager.h"
#include "KeyNameDB.h"
#include "XMLLangFile.h"

// ---------------------------------------------------------------------
//! The base class of application class in each OS.
/*!
	This class provides the function common to the application class for each OS.
	This is abstract class.
*/
// ---------------------------------------------------------------------
class CoveredCalcAppBase : public CoveredCalcApp, public CoverChangeEventHandler
{
public:
											CoveredCalcAppBase();
	virtual									~CoveredCalcAppBase();

	bool									init();
	
	// implementations of CoveredCalcApp interface
	virtual CoverManager*					GetCoverManager() { return &coverManager; }
	virtual AppSettings*					GetAppSettings() { return &appSettings; }
	virtual ExceptionMessageGenerator*		GetExceptionMessageGenerator() { return &exMessageGenerator; }
	virtual CommandLineParam*				GetCommandLineParam() { return &commandLineParam; }
	virtual void							GetCurrentLanguageCode(MBCString& outLanguage);
	virtual const LangFileInfoCollection*	GetLangFileInfos();
	virtual Path							MakeRelativeLangFilePath(const Path& absolutePath);
	virtual Path							MakeAbsoluteLangFilePath(const Path& relativePath);
	virtual Path							ExpandVirtualPath(const Path& virtualPath);
	virtual Path							MakeVirtualPath(const Path& absolutePath, ConstAStr virtualPathName);
	virtual void							LoadKeyMappings(const Path& keymapFile);
	virtual const KeyNameDB*				GetKeyNameDB() const { return &keyNameDB; }
	virtual MBCString						LoadNativeString(SInt32 stringId);
	virtual void							LoadDialogLayout(SInt32 dialogId, DialogLayout& outLayout);
	virtual void							LoadDialogFont(SInt32 /* dialogId */, DialogFont& /* outFont */) { } 
	virtual KeyMappingManager*				GetKeyMappingManagerForMainWindow() { return &mainWindowKeyMappingManager; }

	// implementations of CoverChangeEventHandler interface
	virtual void							CoverDefChanged();
	virtual void							CurrentCoverChanged();	

protected:
	struct LoadedLangFile
	{
		Path				path;		///< path of the language file.
		XMLLangFile			langFile;	///< language file object.
	};
	typedef std::vector<LoadedLangFile*>	LoadedLangFilePtrVector;

protected:
	virtual void							loadLangFile(const Path& path);
	void									loadOneLangFile(const Path& path, LoadedLangFilePtrVector::iterator insertBeforePos);
	void									loadSettings(const Path& settingFile);
	void									loadCoverDef(const Path& basePath, const Path& relativeCoverDefPath, SInt32 coverNo);
	bool									restoreByDefaultCoverDef();
	void									readyLangFileInfos();
	void									setCurrentLanguageCode(ConstAStr language) { currentLangCode = language; }
	virtual Path							resolveVirtualPathName(const MBCString& virtualPathName);
	void 									readyDefaultSettingFilePath(Path& settingFilePath);
	void									loadKeyNameDB(const Path& keyNameDefFile);
	MBCString								loadNativeStringSub(SInt32 stringId);

protected:

	// ---------------------------------------------------------------------
	//! Returns path of application folder (in it, this program exists)
	/*!
		@return result application foler path.
	*/
	// ---------------------------------------------------------------------
	virtual const Path&						getAppFolderPath() = 0;
	
	/**
	 *	@brief	Returns the path of folder in which user settings is stored.
	 *	@return user settings folder path.
	 */
	virtual const Path&						getUserSettingsPath() = 0;
	
	virtual Path							makeAbsoluteCoverDefPath(const Path& basePath, const Path& relativePath);
	virtual Path							makeRelativeCoverDefPath(const Path& basePath, const Path& absolutePath);

protected:
	AppSettings								appSettings;					//!< current application settings
	CoverManager							coverManager;					//!< object which manages current cover
	bool									isIgnoreCoverChangeEvent;		//!< whether ignores CoverChangeEvent
	ExceptionMessageGenerator				exMessageGenerator;				//!< message generator for an exception.
	CommandLineParam						commandLineParam;				///< command line parameters
	LangFileInfoCollection					langFileInfos;					///< informations about installed language files.
	bool									isReadyLangFileInfos;			///< is langFileInfos is loaded?
	MBCString								currentLangCode;				///< current language code.
	KeyMappingManager						mainWindowKeyMappingManager;	///< key-mapping manager for main window.
	KeyNameDB								keyNameDB;						///< key name database.
	LoadedLangFilePtrVector					langFiles;						///< loaded language files.
};

#endif // _COVEREDCALCAPPBASE_H_
