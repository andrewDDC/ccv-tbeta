//
// DNS.h
//
// $Id: //poco/1.3/Net/include/Poco/Net/DNS.h#1 $
//
// Library: Net
// Package: NetCore
// Module:  DNS
//
// Definition of the DNS class.
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


#ifndef Net_DNS_INCLUDED
#define Net_DNS_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/SocketDefs.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/HostEntry.h"
#include "Poco/Mutex.h"
#include <map>


namespace Poco {
namespace Net {


class Net_API DNS
	/// This class provides an interface to the
	/// domain name service.
	///
	/// An internal DNS cache is used to speed up name lookups.
{
public:
	static const HostEntry& hostByName(const std::string& hostname);
		/// Returns a HostEntry object containing the DNS information
		/// for the host with the given name.
		///
		/// Throws a HostNotFoundException if a host with the given
		/// name cannot be found.
		///
		/// Throws a NoAddressFoundException if no address can be
		/// found for the hostname.
		///
		/// Throws a DNSException in case of a general DNS error.
		///
		/// Throws an IOException in case of any other error.
		
	static const HostEntry& hostByAddress(const IPAddress& address);
		/// Returns a HostEntry object containing the DNS information
		/// for the host with the given IP address.
		///
		/// Throws a HostNotFoundException if a host with the given
		/// name cannot be found.
		///
		/// Throws a DNSException in case of a general DNS error.
		///
		/// Throws an IOException in case of any other error.

	static const HostEntry& resolve(const std::string& address);
		/// Returns a HostEntry object containing the DNS information
		/// for the host with the given IP address or host name.
		///
		/// Throws a HostNotFoundException if a host with the given
		/// name cannot be found.
		///
		/// Throws a NoAddressFoundException if no address can be
		/// found for the hostname.
		///
		/// Throws a DNSException in case of a general DNS error.
		///
		/// Throws an IOException in case of any other error.
		
	static IPAddress resolveOne(const std::string& address);
		/// Convenience method that calls resolve(address) and returns 
		/// the first address from the HostInfo.

	static const HostEntry& thisHost();
		/// Returns a HostEntry object containing the DNS information
		/// for this host.
		///
		/// Throws a HostNotFoundException if DNS information 
		/// for this host cannot be found.
		///
		/// Throws a NoAddressFoundException if no address can be
		/// found for this host.
		///
		/// Throws a DNSException in case of a general DNS error.
		///
		/// Throws an IOException in case of any other error.

	static void flushCache();
		/// Flushes the internal DNS cache.

protected:
	static int lastError();
		/// Returns the code of the last error.
		
	static void error(int code, const std::string& arg);
		/// Throws an exception according to the error code.
		
private:
	typedef std::map<std::string, HostEntry> DNSCache;
	
	static DNSCache _cache;
	static Poco::FastMutex _mutex;
};


} } // namespace Poco::Net


#endif // Net_DNS_INCLUDED
