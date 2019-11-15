/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi, <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_consul_rest_DTOs_hpp
#define oatpp_consul_rest_DTOs_hpp

#include "oatpp/encoding/Base64.hpp"

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO codegen */
#include OATPP_CODEGEN_BEGIN(DTO)

namespace oatpp { namespace consul { namespace rest {

/**
 * DTO object representing Consul KV Metadata Response. <br>
 * For More info see [Consul KV Store Endpoints](https://www.consul.io/api/kv.html).
 */
class KVMetadata : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(KVMetadata, Object)

  /**
   * Full path of the entry.
   */
  DTO_FIELD(String, key, "Key");

  /**
   * Value. <br>
   * May contain base64 encoded value if no "raw" parameter were specified in request ex.:`"v1/kv/{key}?raw"`.
   */
  DTO_FIELD(String, value, "Value");

  /**
   * Session.
   */
  DTO_FIELD(String, session, "Session");

  /**
   * Internal index value that represents when the entry was created.
   */
  DTO_FIELD(Int32, createIndex, "CreateIndex");

  /**
   * Last index that modified this key.
   */
  DTO_FIELD(Int32, modifyIndex, "ModifyIndex");

  /**
   * The number of times this key has successfully been acquired in a lock.
   * If the lock is held, the Session key provides the session that owns the lock.
   */
  DTO_FIELD(Int32, lockIndex, "LockIndex");

  /**
   * An opaque unsigned integer that can be attached to each entry.
   */
  DTO_FIELD(Int32, flags, "Flags");
  
private:
  mutable String m_valueDecoded = nullptr;
public:

  /**
   * Get base64 decoded &l:KVMetadata::value;.
   * @return - decoded &l:KVMetadata::value;.
   */
  String getValueDecoded() const {
    if(!m_valueDecoded) {
      if(value) {
        m_valueDecoded = oatpp::encoding::Base64::decode(value);
      } else {
        throw std::runtime_error("[oatpp::consul::rest::KVMetadata::getValueDecoded()]: Value is null. Can't decode value");
      }
    }
    return m_valueDecoded;
  }
  
};

/**
 * DTO Object representing Consul Agent Register Check.<br>
 * For more information see [Consul Agent Register Check](https://www.consul.io/api/agent/check.html#register-check).
 */
class AgentCheckRegisterPayload : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(AgentCheckRegisterPayload, Object)

  /**
   * Name of the check.
   */
  DTO_FIELD(String, name, "Name");

  /**
   * Unique ID for this check on the node.
   */
  DTO_FIELD(String, id, "ID");

  /**
   * Frequency at which to run this check.
   */
  DTO_FIELD(String, interval, "Interval");

  /**
   * Arbitrary information.
   */
  DTO_FIELD(String, notes, "Notes");

  /**
   * Specifies that checks associated with a service should deregister after this time.
   */
  DTO_FIELD(String, deregisterCriticalServiceAfter, "DeregisterCriticalServiceAfter");

  /**
   * Command arguments to run to update the status of the check.
   */
  DTO_FIELD(List<String>::ObjectWrapper, args, "Args");

  /**
   * Specifies that the check is a Docker check.
   */
  DTO_FIELD(String, dockerContainerID, "DockerContainerID");

  /**
   * Specifies a gRPC check's endpoint that supports the standard [gRPC health checking protocol](https://github.com/grpc/grpc/blob/master/doc/health-checking.md).
   */
  DTO_FIELD(String, grpc, "GRPC");

  /**
   * Set `true`to use TLS for this gRPC health check.
   */
  DTO_FIELD(Boolean, grpcUseTLS, "GRPCUseTLS");

  /**
   * HTTP check's endpoint. Default Method is GET.
   */
  DTO_FIELD(String, http, "HTTP");

  /**
   * Specifies a different HTTP method to be used for an HTTP check.
   * If not specified GET is used.
   */
  DTO_FIELD(String, method, "Method");

  /**
   * Set of headers that should be set for HTTP checks.
   */
  DTO_FIELD(Fields<List<String>::ObjectWrapper>::ObjectWrapper, header, "Header");

  /**
   * Timeout for outgoing connections
   */
  DTO_FIELD(String, timeout, "Timeout");

  /**
   * Specifies if the certificate for an HTTPS check should not be verified.
   */
  DTO_FIELD(Boolean, tlsSkipVerify, "TLSSkipVerify");

  /**
   * Specifies a TCP to connect against the value of TCP (expected to be an IP or hostname plus port combination) every Interval.
   */
  DTO_FIELD(String, tcp, "TCP");

  /**
   * Specifies this is a TTL check, and the TTL endpoint must be used periodically to update the state of the check.
   */
  DTO_FIELD(String, ttl, "TTL");

  /**
   * Specifies the ID of a service to associate the registered check with an existing service provided by the agent.
   */
  DTO_FIELD(String, serviceID, "ServiceID");

  /**
   * Initial status of the health check.
   */
  DTO_FIELD(String, status, "Status");
  
};

/**
 * DTO Object representing Consul Agent Register Service.<br>
 * For more information see [Consul Agent Register Service](https://www.consul.io/api/agent/service.html#register-service).
 */
class AgentServiceRegisterPayload : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(AgentServiceRegisterPayload, Object)

  /**
   * Logical name of the service.
   */
  DTO_FIELD(String, name, "Name");

  /**
   * Unique ID for this service.
   */
  DTO_FIELD(String, id, "ID");

  /**
   * List of tags to assign to the service.
   */
  DTO_FIELD(List<String>::ObjectWrapper, tags, "Tags");

  /**
   * Specifies the address of the service. If not provided, the agent's address is used as the address for the service during DNS queries.
   */
  DTO_FIELD(String, address, "Address");

  /**
   * Specifies arbitrary KV metadata linked to the service instance.
   */
  DTO_FIELD(Fields<String>::ObjectWrapper, meta, "Meta");

  /**
   * Port of the service.
   */
  DTO_FIELD(Int32, port, "Port");

  /**
   * The kind of service. Defaults to "" which is a typical Consul service.
   * This value may also be "connect-proxy" for services that are Connect-capable proxies representing another service.
   */
  DTO_FIELD(String, kind, "Kind");

  /**
   * Deprecated.
   */
  DTO_FIELD(String, proxyDestination, "ProxyDestination");
  
  //DTO_FIELD(Connect::ObjectWrapper, connect, "Connect")

  /**
   * &l:AgentCheckRegisterPayload;.
   */
  DTO_FIELD(AgentCheckRegisterPayload::ObjectWrapper, check, "Check");

  /**
   * List of &l:AgentCheckRegisterPayload;.
   */
  DTO_FIELD(List<AgentCheckRegisterPayload::ObjectWrapper>::ObjectWrapper, checks, "Checks");

  /**
   * Specifies to disable the anti-entropy feature for this service's tags.
   */
  DTO_FIELD(Boolean, enableTagOverride, "EnableTagOverride");
  
};


class SessionPayload : public oatpp::data::mapping::type::Object {



	DTO_INIT(SessionPayload, Object)

	
	DTO_FIELD(Int64, createIndex, "CreateIndex");
	DTO_FIELD(String, id, "ID");
	DTO_FIELD(Int64, lockDelay, "LockDelay");
	DTO_FIELD(String, name, "Name");
	DTO_FIELD(String, node, "Node");
	DTO_FIELD(List<String>::ObjectWrapper, cheks, "Checks");
	DTO_FIELD(String, behavior, "Behavior");
	DTO_FIELD(String, ttl, "TTL");


};


}}}

/* End DTO codegen */
#include OATPP_CODEGEN_END(DTO)

#endif /* oatpp_consul_rest_DTOs_hpp */
