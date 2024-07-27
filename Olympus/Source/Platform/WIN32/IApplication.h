#pragma once

class OLYMPUS_API IApplication {

public:
	IApplication();

	virtual ~IApplication() = 0;

public:
	virtual VOID Initialised() = 0;

	virtual VOID Update() = 0;
};