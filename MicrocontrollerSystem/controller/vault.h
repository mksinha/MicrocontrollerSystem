/*
 * vault.h
 *
 * Created: 2/26/2017 6:00:49 PM
 *  Author: Animesh Sinha
 */ 


#if(__OPTION_VAULT)

#ifndef VAULT_H_
#define VAULT_H_

#include <stddef.h>

namespace DeviceController
{
	Device* registeredDevices[32];
	int numberOfDevices = 0;
	char* registeredDeviceId[32];

	void registerDevice(Device* device, char* id)
	{
		registeredDevices[numberOfDevices] = device;
		registeredDeviceId[numberOfDevices] = id;
		numberOfDevices++;
	}

	Device* getDevice(char* id)
	{
		for(int i = 0; i < 32; i++)
		{
			if (registeredDeviceId[i] == id)
				return registeredDevices[i];
		}
		return NULL;
	}
}

#endif

#endif