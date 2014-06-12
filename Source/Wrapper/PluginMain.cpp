/**
 * Copyright (C) 2011-2014 MK124
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
 */

#include "amx_helper.h"
#include "Callbacks.h"
#include "samp.h"

const char SHOEBILL_PUBLIC_MARKER[] = "Shoebill_Oops";

AMX *pAMX = NULL;
logprintf_t logprintf = NULL;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	return OnLoadPlugin();
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	OnUnloadPlugin();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	if (pAMX == NULL)
	{
		int index;
		amx_FindPublic(amx, SHOEBILL_PUBLIC_MARKER, &index);
		if (index != 0x7FFFFFFF)
		{
			pAMX = amx;
			amx_Register(amx, CallbackNatives, -1);

			logprintf("ShoebillPlugin: AMX registered.");
		}
	}

	OnAmxLoad(amx);
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	OnAmxUnload(amx);
	if (pAMX != amx) return AMX_ERR_NONE;

	pAMX = NULL;

	logprintf("ShoebillPlugin: AMX unregistered.");
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	OnProcessTick();
}