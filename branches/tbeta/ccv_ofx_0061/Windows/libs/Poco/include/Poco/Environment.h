//
// Environment.h
//
// $Id: //poco/1.3/Foundation/include/Poco/Environment.h#2 $
//
// Library: Foundation
// Package: Core
// Module:  Environment
//
// Definition of the Environment class.
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


#ifndef Foundation_Environment_INCLUDED
#define Foundation_Environment_INCLUDED


#include "Poco/Foundation.h"


namespace Poco {


class Foundation_API Environment
	/// This class provides access to environment variables
	/// and some general system information.
{
public:
	typedef UInt8 NodeId[6]; /// Ethernet address.
	
	static std::string get(const std::string& name);
		/// Returns the value of the environment variable
		/// with the given name. Throws a NotFoundException
		/// if the variable does not exist.
		
	static std::string get(const std::string& name, const std::string& defaultValue);
		/// Returns the value of the environment variable
		/// with the given name. If the environment variable
		/// is undefined, returns defaultValue instead.
		
	static bool has(const std::string& name);
		/// Returns true iff an environment variable
		/// with the given name is defined.
		
	static void set(const std::string& name, const std::string& value);
		/// Sets the environment variable with the given name
		/// to the given value.

	static std::string osName();
		/// Returns the operating system name.
		
	static std::string osVersion();
		/// Returns the operating system version.
		
	static std::string osArchitecture();
		/// Returns the operating system architecture.
		
	static std::string nodeName();
		/// Returns the node (or host) name.
		
	static void nodeId(NodeId& id);
		/// Returns the Ethernet address of the first Ethernet
		/// adapter found on the system.
		///
		/// Throws a SystemException if no Ethernet adapter is available.
		
	static std::string nodeId();
		/// Returns the Ethernet address (format "xx:xx:xx:xx:xx:xx")
		/// of the first Ethernet adapter found on the system.
		///
		/// Throws a SystemException if no Ethernet adapter is available.
};


} // namespace Poco


#endif // Foundation_Environment_INCLUDED
