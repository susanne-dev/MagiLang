#include <iostream>
#include <sstream>
#include <map>
#include <vector>

namespace MagiLang
{
	struct astNode;
}

using namespace MagiLang;

namespace Memory
{
	struct Register
	{
		long long NUM;
		long double DEC;
		std::string	STR;
		bool BOOL;
	};

	struct Storage //Interpreter memory
	{
		Register registerA;
		Register registerB;
		bool success; //Did the sub node operation succeed? vital for knowing if + as subnde of = can do math.
	};

	struct memNode
	{
		memNode* MEMparent = nullptr;
		astNode* ASTparent = nullptr;
		std::vector<char*> names;
		std::map<char*, long long*> NUMs;
		std::map<char*, long double*> DECs;
		std::map<char*, std::string*> STRs;
		std::map<char*, bool*> BOOLs;
		std::map<char*, astNode*> OBJECTs;

		memNode(astNode* parent)
		{
			ASTparent = parent;
		}

		operator std::string() const 
		{
			std::stringstream ss;
			ss << MEMparent;
			std::string outpt = "{MEMparent: " + ss.str() + "}";
			ss.str("");
			ss << ASTparent;
			outpt += " {ASTparent: " + ss.str() + "}";
			return outpt;
		}

		friend std::ostream& operator<<(std::ostream& os, const memNode& n) 
		{
			os << "{memNode} ";
			os << "MEMparent: " << n.MEMparent << ", ASTparent: " << n.ASTparent << "\n";

			if (!n.names.empty())
			{
				os << "Names: ";
				for (auto& name : n.names) os << name << " ";
				os << "\n";
			}

			if (!n.NUMs.empty())
			{
				os << "NUMs: ";
				for (auto& [k, v] : n.NUMs) os << k << "=" << *v << " ";
				os << "\n";
			}

			if (!n.DECs.empty())
			{
				os << "DECs: ";
				for (auto& [k, v] : n.DECs) os << k << "=" << *v << " ";
				os << "\n";
			}

			if (!n.STRs.empty())
			{
				os << "STRs: ";
				for (auto& [k, v] : n.STRs) os << k << "=\"" << *v << "\" ";
				os << "\n";
			}

			if (!n.BOOLs.empty())
			{
				os << "BOOLs: ";
				for (auto& [k, v] : n.BOOLs) os << k << "=" << (*v ? "true" : "false") << " ";
				os << "\n";
			}

			if (!n.OBJECTs.empty())
			{
				os << "OBJECTs: ";
				for (auto& [k, v] : n.OBJECTs) os << k << "=" << v << " ";
				os << "\n";
			}

			return os;
		}

		friend std::wostream& operator<<(std::wostream& os, const memNode& n) 
		{
			os << L"{memNode} ";
			os << L"MEMparent: " << n.MEMparent << L", ASTparent: " << n.ASTparent << L"\n";

			if (!n.names.empty())
			{
				os << L"Names: ";
				for (auto& name : n.names) os << name << L" ";
				os << L"\n";
			}

			if (!n.NUMs.empty())
			{
				os << L"NUMs: ";
				for (auto& [k, v] : n.NUMs) os << k << L"=" << *v << L" ";
				os << L"\n";
			}

			if (!n.DECs.empty())
			{
				os << L"DECs: ";
				for (auto& [k, v] : n.DECs) os << k << L"=" << *v << L" ";
				os << L"\n";
			}

			if (!n.STRs.empty())
			{
				os << L"STRs: ";
				for (auto& [k, v] : n.STRs) 
					os << k << L"=\"" << std::wstring(v->begin(), v->end()) << L"\" ";
				os << L"\n";
			}

			if (!n.BOOLs.empty())
			{
				os << L"BOOLs: ";
				for (auto& [k, v] : n.BOOLs) os << k << L"=" << (*v ? L"true" : L"false") << L" ";
				os << L"\n";
			}

			if (!n.OBJECTs.empty())
			{
				os << L"OBJECTs: ";
				for (auto& [k, v] : n.OBJECTs) os << k << L"=" << v << L" ";
				os << L"\n";
			}

			return os;
		}
	};
}