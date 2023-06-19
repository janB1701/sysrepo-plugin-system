#pragma once

#include <srpcpp/module.hpp>
#include <core/ip.hpp>

#include <sysrepo-cpp/Subscription.hpp>
#include <libyang-cpp/Context.hpp>

// helpers
namespace sr = sysrepo;
namespace ly = libyang;

namespace ietf::sys::dns {
// /**
//  * @brief DNS server.
//  */
// class DnsServer {
// private:
//     std::string m_name; ///< Arbitrary name of the DNS server.
//     ip::Address m_address; ///< Address of the DNS server.
//     std::uint16_t m_port; ///< Port of the DNS server.
//     int m_ifindex;

// public:
//     DnsServer(int ifindex, std::string name, ip::Address address, std::uint16_t port);
//     // void setName(const std::string name);
//     void setAddress(const ip::Address& address);
//     void setPort(const uint16_t& port);
//     std::string getName();
//     std::string getStringAddress();
//     ip::Address* getAddress();
//     std::uint16_t getPort();
//     int getIfindex();

//     bool operator==(const DnsServer& other) const;
//     bool operator!=(const DnsServer& other) const;
// };

// /**
//  * @brief DnsSearchServer class
//  */
// class DnsSearchServer {

// private:
//     std::string m_domain;
//     bool m_search;
//     int m_ifindex;

// public:
//     /**
//      * @brief Default constructor
//      */
//     DnsSearchServer();

//     /**
//      * @brief Constructor with all parameters
//      */
//     DnsSearchServer(int ifindex, std::string domain, bool search);
//     DnsSearchServer(std::string domain, bool search);

//     /**
//      * @brief Return the ifindes
//      */
//     int getIfIndex();

//     // /**
//     //  * @brief set the ifindex
//     //  */
//     // void setIfIndex(const int& ifindex);

//     /**
//      * @brief Set DnsSearchServer Domain
//      */
//     void setDomain(std::string domain);

//     /**
//      * @brief Set DnsSearchServer search
//      */
//     void setSearch(bool search);

//     /**
//      * @brief Get DnsSearchServer Domain
//      */
//     std::string getDomain();

//     /**
//      * @brief Get DnsSearchServer Search
//      */
//     bool getSearch();

//     /**
//      * @brief Overloaded == operator
//      * @details It compares them by the Domain
//      */
//     bool operator==(const DnsSearchServer& other) const;

//     /**
//      * @brief Overloaded != operator
//      * @details It compares them by the Domain
//      */
//     bool operator!=(const DnsSearchServer& other) const;
// };

// /**
//  * @brief DnsSearchServerList class
//  * @details Static class for storring DnsSearchServer objects
//  */

// class DnsSearchServerList {

// private:
//     int m_ifindex;
//     std::vector<DnsSearchServer> m_servers;

// public:
//     DnsSearchServerList();
//     DnsSearchServerList(int ifindex);

//     // void setIfIndex(const int& ifindex);
//     int getIfIndex();
//     bool addDnsSearchServer(DnsSearchServer srv);
//     std::vector<DnsSearchServer> getAllServers();

//     /**
//      * @brief Find DnsSearchServer by DnsSearchServer
//      * @return std::optional<DnsSearchServer>
//      * @details Returns std::nullopt if object is not found
//      */
//     std::optional<DnsSearchServer> findDnsSearchServer(const DnsSearchServer& server);

//     /**
//      * @brief Remove DnsSearchServer
//      * @return true if removed, false otherwise
//      */
//     bool removeDnsSearchServer(const DnsSearchServer& server);

//     /**
//      * @brief Compare DnsSearchServer
//      * @param s1,s2 Compares 2 DnsSearchServers
//      * @return true if are the same, false otherwise
//      */
//     bool compareDnsSearchServer(const DnsSearchServer& s1, const DnsSearchServer& s2);

//     /**
//      * @brief Call sdbus command with current object
//      */
//     bool exportListToSdBus();

//     /**
//      * @warning it overwrites all existing dns search servers
//      * @brief Get all Domains from sdbus
//      */
//     bool importListFromSdBus();
// };

// class DnsServerList {
// private:
//     int m_ifindex;
//     std::vector<DnsServer> m_servers;

// public:
//     DnsServerList();
//     DnsServerList(int ifindex);

//     int getIfIndex();
//     bool addDnsServer(DnsServer srv);

//     bool removeDnsServer(const DnsServer& server);

//     bool exportListToSdBus();

//     bool importListFromSdBus();

//     bool modifyDnsServer(DnsServer server);

//     std::vector<DnsServer> getDnsServerVector();
// };

// std::optional<DnsServer> getServerFromChangedNode(const libyang::DataNode& changedNode);
}

/**
 * Operational context for the DNS module.
 */
class DnsOperationalContext : public srpc::IModuleContext { };

/**
 * Module changes context for the DNS module.
 */
class DnsModuleChangesContext : public srpc::IModuleContext { };

/**
 * RPC context for the DNS module.
 */
class DnsRpcContext : public srpc::IModuleContext { };

namespace ietf::sys::sub::oper {
/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/search.
 */
class DnsSearchOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsSearchOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/search.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/server[name='%s']/name.
 */
class DnsServerNameOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsServerNameOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/server[name='%s']/name.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path
 * /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp/address.
 */
class DnsServerUdpAndTcpAddressOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsServerUdpAndTcpAddressOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path
     * /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp/address.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path
 * /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp/port.
 */
class DnsServerUdpAndTcpPortOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsServerUdpAndTcpPortOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path
     * /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp/port.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp.
 */
class DnsServerUdpAndTcpOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsServerUdpAndTcpOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/server[name='%s']/udp-and-tcp.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/server[name='%s'].
 */
class DnsServerOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsServerOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/server[name='%s'].
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/options/timeout.
 */
class DnsOptionsTimeoutOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsOptionsTimeoutOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/options/timeout.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/options/attempts.
 */
class DnsOptionsAttemptsOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsOptionsAttemptsOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/options/attempts.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver/options.
 */
class DnsOptionsOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsOptionsOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver/options.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated operational get functor for path /ietf-system:system/dns-resolver.
 */
class DnsOperGetCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin operational context.
     *
     */
    DnsOperGetCb(std::shared_ptr<DnsOperationalContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated operational get operator() for path /ietf-system:system/dns-resolver.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * @param output A handle to a tree. The callback is supposed to fill this tree with the requested data.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        std::optional<std::string_view> requestXPath, uint32_t requestId, std::optional<ly::DataNode>& output);

private:
    std::shared_ptr<DnsOperationalContext> m_ctx;
};

}

namespace ietf::sys::sub::change {
/**
 * @brief sysrepo-plugin-generator: Generated module change functor for path /ietf-system:system/dns-resolver/search.
 */
class DnsSearchModuleChangeCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin module change context.
     *
     */
    DnsSearchModuleChangeCb(std::shared_ptr<DnsModuleChangesContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated module change operator() for path /ietf-system:system/dns-resolver/search.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param event Type of the event that has occured.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * SR_EV_DONE, for example) have the same request ID.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        sr::Event event, uint32_t requestId);

private:
    std::shared_ptr<DnsModuleChangesContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated module change functor for path /ietf-system:system/dns-resolver/server[name='%s'].
 */
class DnsServerModuleChangeCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin module change context.
     *
     */
    DnsServerModuleChangeCb(std::shared_ptr<DnsModuleChangesContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated module change operator() for path /ietf-system:system/dns-resolver/server[name='%s'].
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param event Type of the event that has occured.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * SR_EV_DONE, for example) have the same request ID.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        sr::Event event, uint32_t requestId);

private:
    std::shared_ptr<DnsModuleChangesContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated module change functor for path /ietf-system:system/dns-resolver/options/timeout.
 */
class DnsTimeoutModuleChangeCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin module change context.
     *
     */
    DnsTimeoutModuleChangeCb(std::shared_ptr<DnsModuleChangesContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated module change operator() for path /ietf-system:system/dns-resolver/options/timeout.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param event Type of the event that has occured.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * SR_EV_DONE, for example) have the same request ID.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        sr::Event event, uint32_t requestId);

private:
    std::shared_ptr<DnsModuleChangesContext> m_ctx;
};

/**
 * @brief sysrepo-plugin-generator: Generated module change functor for path /ietf-system:system/dns-resolver/options/attempts.
 */
class DnsAttemptsModuleChangeCb {
public:
    /**
     * sysrepo-plugin-generator: Generated default constructor.
     *
     * @param ctx Plugin module change context.
     *
     */
    DnsAttemptsModuleChangeCb(std::shared_ptr<DnsModuleChangesContext> ctx);

    /**
     * sysrepo-plugin-generator: Generated module change operator() for path /ietf-system:system/dns-resolver/options/attempts.
     *
     * @param session An implicit session for the callback.
     * @param subscriptionId ID the subscription associated with the callback.
     * @param moduleName The module name used for subscribing.
     * @param subXPath The optional xpath used at the time of subscription.
     * @param event Type of the event that has occured.
     * @param requestId Request ID unique for the specific module_name. Connected events for one request (SR_EV_CHANGE and
     * SR_EV_DONE, for example) have the same request ID.
     *
     * @return Error code.
     *
     */
    sr::ErrorCode operator()(sr::Session session, uint32_t subscriptionId, std::string_view moduleName, std::optional<std::string_view> subXPath,
        sr::Event event, uint32_t requestId);

private:
    std::shared_ptr<DnsModuleChangesContext> m_ctx;
};
}

/**
 * @brief DNS container module.
 */
class DnsModule : public srpc::IModule {
public:
    /**
     * DNS module constructor. Allocates each context.
     */
    DnsModule();

    /**
     * Return the operational context from the module.
     */
    virtual std::shared_ptr<srpc::IModuleContext> getOperationalContext() override;

    /**
     * Return the module changes context from the module.
     */
    virtual std::shared_ptr<srpc::IModuleContext> getModuleChangesContext() override;

    /**
     * Return the RPC context from the module.
     */
    virtual std::shared_ptr<srpc::IModuleContext> getRpcContext() override;

    /**
     * Get all operational callbacks which the module should use.
     */
    virtual std::list<OperationalCallback> getOperationalCallbacks() override;

    /**
     * Get all module change callbacks which the module should use.
     */
    virtual std::list<ModuleChangeCallback> getModuleChangeCallbacks() override;

    /**
     * Get all RPC callbacks which the module should use.
     */
    virtual std::list<RpcCallback> getRpcCallbacks() override;

    /**
     * Get module name.
     */
    virtual constexpr const char* getName() override;

    /**
     * Dns module destructor.
     */
    ~DnsModule() { }

private:
    std::shared_ptr<DnsOperationalContext> m_operContext;
    std::shared_ptr<DnsModuleChangesContext> m_changeContext;
    std::shared_ptr<DnsRpcContext> m_rpcContext;
};