// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "jsonrpc/types.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearSimulation, Log, All);

using namespace ApiGear;

namespace ApiGear { namespace JSONRPC {
class RpcProtocol;
} }

class APIGEAR_API UnrealSimulation : public JSONRPC::IMessageWriter, public JSONRPC::IRpcProtocolListener, public JSONRPC::ILogger
{
public:
    static UnrealSimulation* instance();
    UnrealSimulation(UnrealSimulation const&) = delete;
    void operator=(UnrealSimulation const&) = delete;
    virtual ~UnrealSimulation() override;

    void doFetchState(std::string service, JSONRPC::CallResponseFunc& func);
    void doCall(std::string service, std::string operation, JSONRPC::Params args, JSONRPC::CallResponseFunc& func);
    void doCall(std::string service, std::string operation, JSONRPC::Params args);
    void onNotify(std::string method, JSONRPC::NotifyRequestFunc &func);
    void onNotifyState(std::string service, JSONRPC::NotifyRequestFunc &func);
    void notify(JSONRPC::NotifyRequestArg args);

    void log(const FString &logMessage);
    void onConnected();
    void onDisconnected();
    void handleTextMessage(const FString& message);
    
    void info(std::string message) override;
    void debug(std::string message) override;
    void warning(std::string message) override;
    void error(std::string message) override;
    // IMessageWriter interface
public:
    virtual void writeMessage(std::string message) override;
    void onNotify(std::string method, JSONRPC::Params params) override;
    void RemoveOnNotify(std::string method);
    void RemoveOnNotifyState(std::string service);
    void RegisterSignalCallback(JSONRPC::NotifyRequestArg args);
private:
    explicit UnrealSimulation();
    void open(const FString& url);

    static UnrealSimulation* s_instance;
    TSharedPtr<IWebSocket> m_socket;
    ApiGear::JSONRPC::RpcProtocol *m_session;
    bool m_loggingDisabled;
    FString m_serverURL;
    std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyRegistry;
    std::map<std::string, JSONRPC::NotifyRequestFunc> m_notifyStateRegistry;
};
