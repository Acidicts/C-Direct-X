#pragma once

class IApplication {

public:
	IApplication();

	virtual ~IApplication() = 0;

private:
	virtual VOID Initialised() = 0;

	virtual VOID Update() = 0;
};