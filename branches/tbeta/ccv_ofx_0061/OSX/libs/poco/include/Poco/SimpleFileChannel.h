//
// SimpleFileChannel.h
//
// $Id: //poco/1.3/Foundation/include/Poco/SimpleFileChannel.h#1 $
//
// Library: Foundation
// Package: Logging
// Module:  SimpleFileChannel
//
// Definition of the SimpleFileChannel class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_SimpleFileChannel_INCLUDED
#define Foundation_SimpleFileChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"
#include "Poco/Timestamp.h"
#include "Poco/Mutex.h"


namespace Poco {


class LogFile;


class Foundation_API SimpleFileChannel: public Channel
	/// A Channel that writes to a file. This class only
	/// supports simple log file rotation.
	///
	/// For more features, see the FileChannel class.
	///
	/// Only the message's text is written, followed
	/// by a newline.
	///
	/// Chain this channel to a FormattingChannel with an
	/// appropriate Formatter to control what is in the text. 
	///
	/// Log file rotation based on log file size is supported.
	///
	/// If rotation is enabled, the SimpleFileChannel will 
	/// alternate between two log files. If the size of
	/// the primary log file exceeds a specified limit,
	/// the secondary log file will be used, and vice
	/// versa. 
	///
	/// Log rotation is configured with the "rotation"
	/// property, which supports the following values:
	///   * never:         no log rotation
	///   * <n>:           the file is rotated when its size exceeds
	///                    <n> bytes.
	///   * <n> K:         the file is rotated when its size exceeds
	///                    <n> Kilobytes.
	///   * <n> M:         the file is rotated when its size exceeds
	///                    <n> Megabytes.
	///
	/// The path of the (primary) log file can be specified with
	/// the "path" property. Optionally, the path of the secondary
	/// log file can be specified with the "secondaryPath" property.
	///
	/// If no secondary path is specified, the secondary path will
	/// default to <primaryPath>.1.
{
public:
	SimpleFileChannel();
		/// Creates the FileChannel.

	SimpleFileChannel(const std::string& path);
		/// Creates the FileChannel for a file with the given path.

	void open();
		/// Opens the FileChannel and creates the log file if necessary.
		
	void close();
		/// Closes the FileChannel.

	void log(const Message& msg);
		/// Logs the given message to the file.
		
	void setProperty(const std::string& name, const std::string& value);
		/// Sets the property with the given name. 
		/// 
		/// The following properties are supported:
		///   * path:          The primary log file's path.
		///   * secondaryPath: The secondary log file's path.
		///   * rotation:      The log file's rotation mode. See the 
		///                    SimpleFileChannel class for details.

	std::string getProperty(const std::string& name) const;
		/// Returns the value of the property with the given name.
		/// See setProperty() for a description of the supported
		/// properties.

	Timestamp creationDate() const;
		/// Returns the log file's creation date.
		
	UInt64 size() const;
		/// Returns the log file's current size in bytes.

	const std::string& path() const;
		/// Returns the log file's primary path.

	const std::string& secondaryPath() const;
		/// Returns the log file's secondary path.

	static const std::string PROP_PATH;
	static const std::string PROP_SECONDARYPATH;
	static const std::string PROP_ROTATION;

protected:
	~SimpleFileChannel();
	void setRotation(const std::string& rotation);
	void rotate();

private:
	std::string      _path;
	std::string      _secondaryPath;
	std::string      _rotation;
	UInt64           _limit;
	LogFile*         _pFile;
	FastMutex        _mutex;
};


} // namespace Poco


#endif // Foundation_SimpleFileChannel_INCLUDED
