/*
    Initial author: (https://github.com/)Convery for Ayria.se
    License: MIT
    Started: 2016-12-22
    Notes:
        Entrypoint for the plugin, proposed 2017 standard.
*/

#include "STDInclude.h"

// The entrypoints that will be called by the bootstrap.
#pragma region Pluginexports
extern "C"
{
    EXPORT_ATTR void __cdecl onExtensionUnloading(void)
    {
        /*
            This export is called for each plugin when the game exists.
            It should be used to save your configurations and similar info.
        */
    }
    EXPORT_ATTR void __cdecl onInitializationStart(void)
    {
        /*
            This export is called when all other dlls and plugins have been loaded.
            It should be used to do your initialization and .text segment modifications.
        */
    }
    EXPORT_ATTR void __cdecl onInitializationComplete(void)
    {
        /*
            This export is called either 3 seconds after the start or when
            another plugin such as AyriaPlatform notifies the bootstrap loader.
            It should be used to do your memory modifications.
        */
    }

#pragma region Optional
    EXPORT_ATTR void __cdecl onMessage(uint32_t MessageID, uint32_t Buffersize, const char *Bufferdata)
    {
        /*
            This export is used called when a plugin broadcasts a message.
            As such you'll want a unique messageID, we suggest a hash of a
            string that's prefixed with your plugins name.

            The bytebuffer class should be included in the utility folder.
        */

#ifdef BYTEBUFFER_IMPL
        Bytebuffer Message(Buffersize, Bufferdata);

        switch (MessageID)
        {
            case AYRIA::FNV1::Compiletime::FNV1_32("MyPlugin_Default"):
            default:
        }
#endif
    }
    EXPORT_ATTR const char *__cdecl Friendlyname(void)
    {
        /*
            The public JSON package file should contain this name.
            But the author can override it through this export.
        */

        return "MyPlugin by Author";
    }
#pragma endregion
}
#pragma endregion

// The entrypoint of the plugin, do not initialize anything.
#pragma region Pluginentry
#ifndef _WIN32
// Entrypoint on *nix systems.
void __attribute__((constructor)) PluginMain(void)
{
    // Remove the old logfile from the directory.
    AYRIA::DEBUG::DeleteLogfile();
}
#endif
