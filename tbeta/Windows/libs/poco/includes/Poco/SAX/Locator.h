//
// Locator.h
//
// $Id: //poco/svn/XML/include/Poco/SAX/Locator.h#2 $
//
// Library: XML
// Package: SAX
// Module:  SAX
//
// SAX Locator Interface.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef SAX_Locator_INCLUDED
#define SAX_Locator_INCLUDED


#include "Poco/XML/XML.h"
#include "Poco/XML/XMLString.h"


namespace Poco {
namespace XML {


class XML_API Locator
	/// Interface for associating a SAX event with a document location.
	/// 
	/// If a SAX parser provides location information to the SAX application, it does so by 
	/// implementing this interface and then passing an instance to the application using the 
	/// content handler's setDocumentLocator method. The application can use the object to obtain 
	/// the location of any other SAX event in the XML source document.
	/// 
	/// Note that the results returned by the object will be valid only during the scope of each 
	/// callback method: the application will receive unpredictable results if it attempts to use 
	/// the locator at any other time, or after parsing completes.
	/// 
	/// SAX parsers are not required to supply a locator, but they are very strongly encouraged to 
	/// do so. If the parser supplies a locator, it must do so before reporting any other document 
	/// events. If no locator has been set by the time the application receives the startDocument event, 
	/// the application should assume that a locator is not available.
{
public:
	virtual XMLString getPublicId() const = 0;
		/// Return the public identifier for the current document event.
		/// 
		/// The return value is the public identifier of the document entity or of the external 
		/// parsed entity in which the markup triggering the event appears.

	virtual XMLString getSystemId() const = 0;
		/// Return the system identifier for the current document event.
		/// 
		/// The return value is the system identifier of the document entity or of the external 
		/// parsed entity in which the markup triggering the event appears.
		/// 
		/// If the system identifier is a URL, the parser must resolve it fully before passing 
		/// it to the application. For example, a file name must always be provided as a 
		/// file:... URL, and other kinds of relative URI are also resolved against their bases.

	virtual int getLineNumber() const = 0;
		/// Return the line number where the current document event ends.
		/// Lines are delimited by line ends, which are defined in the XML specification.
		/// 
		/// Warning: The return value from the method is intended only as an approximation for 
		/// the sake of diagnostics; it is not intended to provide sufficient information to 
		/// edit the character content of the original XML document. In some cases, these "line" 
		/// numbers match what would be displayed as columns, and in others they may not match the 
		/// source text due to internal entity expansion.
		/// 
		/// The return value is an approximation of the line number in the document entity or external 
		/// parsed entity where the markup triggering the event appears.
		/// 
		/// If possible, the SAX driver should provide the line position of the first character after 
		/// the text associated with the document event. The first line is line 1.

	virtual int getColumnNumber() const = 0;
		/// Return the column number where the current document event ends. 
		/// This is one-based number of characters since the last line end.
		/// 
		/// Warning: The return value from the method is intended only as an approximation 
		/// for the sake of diagnostics; it is not intended to provide sufficient information 
		/// to edit the character content of the original XML document. For example, when lines 
		/// contain combining character sequences, wide characters, surrogate pairs, or bi-directional 
		/// text, the value may not correspond to the column in a text editor's display.
		/// 
		/// The return value is an approximation of the column number in the document entity or external 
		/// parsed entity where the markup triggering the event appears.
		/// 
		/// If possible, the SAX driver should provide the line position of the first character after 
		/// the text associated with the document event. The first column in each line is column 1.

protected:
	virtual ~Locator();
};


} } // namespace Poco::XML


#endif // SAX_Locator_INCLUDED
