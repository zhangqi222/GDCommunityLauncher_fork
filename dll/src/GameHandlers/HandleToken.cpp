#include <filesystem>
#include "GameHandler.h"
#include "EventManager.h"
#include "URI.h"

void HandleBestowToken(void* _this, const GameAPI::TriggerToken& token)
{
    typedef void (__thiscall* BestowTokenProto)(void*, const GameAPI::TriggerToken&);

    BestowTokenProto callback = (BestowTokenProto)HookManager::GetOriginalFunction(GAME_DLL, GameAPI::GAPI_NAME_BESTOW_TOKEN);
    if (callback)
    {
        if ((EngineAPI::IsMainCampaign()) && (spClient->IsPlayingSeason()))
        {
            std::string tokenString = token;
            for (char& c : tokenString)
                c = std::tolower(c);

            // Prevent tokens from being updated in multiplayer season games (except for starting item token, to avoid receiving the starting items multiple times)
            if (((EngineAPI::IsMultiplayer()) || (GameAPI::IsCloudStorageEnabled())) && (tokenString != "received_start_items"))
                return;

            EventManager::Publish(GDCL_EVENT_BESTOW_TOKEN, tokenString);
        }

        callback(_this, token);
    }
}

void HandleRemoveToken(void* _this, const GameAPI::TriggerToken& token)
{
    typedef void (__thiscall* RemoveTokenProto)(void*, const GameAPI::TriggerToken&);

    RemoveTokenProto callback = (RemoveTokenProto)HookManager::GetOriginalFunction(GAME_DLL, GameAPI::GAPI_NAME_REMOVE_TOKEN);
    if (callback)
    {
        if ((EngineAPI::IsMainCampaign()) && (spClient->IsPlayingSeason()))
        {
            std::string tokenString = token;
            for (char& c : tokenString)
                c = std::tolower(c);

            EventManager::Publish(GDCL_EVENT_REMOVE_TOKEN, tokenString);
        }

        callback(_this, token);
    }
}