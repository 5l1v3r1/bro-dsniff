// Generated by binpac_quickstart

#ifndef ANALYZER_PROTOCOL_TELNET__TELNET__H
#define ANALYZER_PROTOCOL_TELNET__TELNET__H

#include "events.bif.h"


#include "analyzer/protocol/tcp/TCP.h"

#include "telnet__pac.h"

namespace analyzer { namespace telnet_ {

class TELNET__Analyzer

: public tcp::TCP_ApplicationAnalyzer {

public:
	TELNET__Analyzer(Connection* conn);
	virtual ~TELNET__Analyzer();

	// Overriden from Analyzer.
	virtual void Done();
	
	virtual void DeliverStream(int len, const u_char* data, bool orig);
	virtual void Undelivered(uint64 seq, int len, bool orig);

	// Overriden from tcp::TCP_ApplicationAnalyzer.
	virtual void EndpointEOF(bool is_orig);
	

	static analyzer::Analyzer* InstantiateAnalyzer(Connection* conn)
		{ return new TELNET__Analyzer(conn); }

protected:
	binpac::TELNET_::TELNET__Conn* interp;
	
	bool had_gap;
	
};

} } // namespace analyzer::* 

#endif