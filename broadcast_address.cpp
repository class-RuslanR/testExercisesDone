#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool Validate(uint32_t& value)
{
	if (value < 0 || value > 255) return false;
	return true;
}

std::vector<uint32_t> SplitIP(std::string& ipAddress)
{
	std::vector<uint32_t> ipAddr;
	std::stringstream ssIP(ipAddress);
	std::string ipAddressTemp;
	while (std::getline(ssIP, ipAddressTemp, '.'))
	{
		uint32_t tempIP = std::stoi(ipAddressTemp);
		if (Validate(tempIP)) ipAddr.push_back(tempIP);
		else
		{
			std::cout << "Invalid IP Address" << std::endl;
		}
	}
	return ipAddr;
}

std::vector<uint32_t> SplitMask(std::string& maskSubnet)
{
	std::vector<uint32_t> maskNet;
	std::stringstream ssMask(maskSubnet);
	std::string maskSubnetTemp;
	while (std::getline(ssMask, maskSubnetTemp, '.'))
	{
		uint32_t tempMask = std::stoi(maskSubnetTemp);
		if (Validate(tempMask)) maskNet.push_back(tempMask);
		else
		{
			std::cout << "Invalid mask subnet's" << std::endl;
		}
	}
	return maskNet;
}

std::string CalcBroadCastAddress(std::vector<uint32_t>& ipAddr, std::vector<uint32_t>& maskNet)
{
	std::vector<uint32_t> broadCastAddress;
	std::string broadCastAddrforSend;
	int oktets = 4;
	for (int i = 0; i < oktets; ++i)
	{
		broadCastAddress.push_back((ipAddr[i]) | (maskNet[i] ^ 255));
	}
	std::cout << "\nBroadcast address: ";
	int counter = 0;
	for (const auto& i : broadCastAddress)
	{
		if (counter != 3)
		{
			broadCastAddrforSend += std::to_string(i) + '.';
		}
		else
		{
			broadCastAddrforSend += std::to_string(i);
		}
		++counter;
	}
	return broadCastAddrforSend;
}

int main()
{
	std::string ipAddress = "192.168.64.1";
	std::string maskSubnet = "255.255.254.0";
	std::cout << "IP address:\t" << ipAddress << std::endl;
	std::cout << "Mask of subnet: " << maskSubnet << std::endl;

	std::vector<uint32_t> ipAddr;
	std::vector<uint32_t> maskNet;

	ipAddr = SplitIP(ipAddress);
	maskNet = SplitMask(maskSubnet);
	
	std::cout << CalcBroadCastAddress(ipAddr, maskNet) << std::endl;
}