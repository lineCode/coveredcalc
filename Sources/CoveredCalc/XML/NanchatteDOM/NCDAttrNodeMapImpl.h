/*
 * CoveredCalc
 *
 * Copyright (c) 2004-2007 CoveredCalc Project Contributors
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
	@file		NCDAttrNodeMapImpl.h
	@brief		Definition of NCDAttrNodeMapImpl class
	@author		ICHIMIYA Hironori (Hiron)
	@date		2005.05.20 created
*/

#ifndef _NCDATTRNODEMAPIMPL_H_
#define _NCDATTRNODEMAPIMPL_H_

#include "NCDNamedNodeMap.h"
#include <vector>
#include "UTF8String.h"

class NCDElement;
class NCDAttr;

namespace NanchatteDOMImpl {

/**
 * This class implements NCDNamedNodeMap interface.
 */
class NCDAttrNodeMapImpl : public NCDNamedNodeMap
{
public:
								NCDAttrNodeMapImpl();
	virtual						~NCDAttrNodeMapImpl();

	void						Init(NCDElement* ownerElement);

	// implementation of NCDNamedNodeMap
	virtual NCDNode*			getNamedItem(ConstUTF8Str name) const;
	virtual NCDNode*			setNamedItem(NCDNode* arg);			
	virtual NCDNode*			removeNamedItem(ConstUTF8Str name);	

	virtual NCDNode*			item(UInt32 index) const;
	virtual UInt32				getLength() const;

	// NCDAttr-specific functions.
	NCDAttr*					getAttrItem(ConstUTF8Str name) const;
	NCDAttr*					setAttrItem(NCDAttr* arg);
	NCDAttr*					removeAttrItem(ConstUTF8Str name);
	NCDAttr*					attrItem(UInt32 index) const;

private:
	typedef std::vector<NCDAttr*>	AttrNodeVector;

private:
	NCDElement*					ownerElement;			///< owner element
	AttrNodeVector				attrNodes;				///< attribute nodes
};

}	// namespace NanchatteDOMImpl

#endif // _NCDNAMEDNODEMAPIMPL_H_
