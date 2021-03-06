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
	@file		WinNormalAppearance.h
	@brief		Definition of WinNormalAppearance class.
	@author		ICHIMIYA Hironori (Hiron)
	@date		2007.4.7 created
*/

#ifndef _WINNORMALAPPEARANCE_H_
#define _WINNORMALAPPEARANCE_H_

#include "WinCCSAppearance.h"
#include "WinDIBitmapDC.h"

// ---------------------------------------------------------------------
//! Windows 用 ColorCodedSkinApperance の標準実装クラス
// ---------------------------------------------------------------------
class WinNormalAppearance : public WinCCSAppearance
{
public:
							WinNormalAppearance();
	virtual					~WinNormalAppearance();

	void					Init(HWND hWnd);
	void					Exit();
	
	virtual bool			RelayWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* ret);
	virtual void			UpdateAppearance();

	virtual void			ChangeSkinSize(SInt32 width, SInt32 height);
	virtual void			ClipSkinRegion(const DIBitmap* mapBitmap, ColorValue transparentColor);
	virtual void			UnclipSkinRegion();
	virtual	void			UpdateMapArea(const Rect32& areaRect, const DIBitmap* mapBitmap, ColorValue color, const DIBitmap* skinBitmap);
	virtual void			UpdateMapAreaWithBlend(const Rect32& areaRect, const DIBitmap* mapBitmap, ColorValue color, const DIBitmap* skinBitmap1, const DIBitmap* skinBitmap2, UInt32 ratio);
	virtual	void			UpdateRect(const Rect32& skinRect, const DIBitmap* skinBitmap);
	virtual void			OverpaintImage(const Point32& drawPoint, const DIBitmap* sourceBitmap, const Rect32& sourceRect, const ColorValue* transparentColor);

private:
	void					invalidateRect(const Point32& drawPoint, const Rect32& skinRect);

private:
	HWND					hWnd;
	WinDIBitmapDC			dibitmapDC;
	HRGN					hWndRgn;
};

#endif // _WINNORMALAPPEARANCE_H_