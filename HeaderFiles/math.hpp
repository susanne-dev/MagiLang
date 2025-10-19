#pragma once
#include "node.hpp"
#include "errorClass.hpp"

namespace MagiLang
{
	struct token;
	struct astNode;

	template <typename T1, typename T2>
	void binary(std::string oprtr, token* v1, token* v2, token* outpt, std::vector<MagiLang::errorClass>* errorList)
	{

	}

	void arithmetic(std::string oprtr, token* v1, token* v2, token* outpt, std::vector<MagiLang::errorClass>* errorList)
	{
		/*astNode temp = astNode(v1);
		//printAST(temp, "", "Run");

		if (oprtr == "+")
		{
			switch (v1->valuetype)
			{
				case MagiLang::token::NUMBER:
				{
					v1->valuetype = MagiLang::token::NUMBER;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						std::cout << "AA" << std::endl;
						outpt->value = new long long;
						*((long long*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
						std::cout << "BB" << std::endl;
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long long*)outpt->value) = *((long long*)v1->value) + *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;

					}
				}
				break;
				case MagiLang::token::DECIMAL:
				{
					v1->valuetype = MagiLang::token::DECIMAL;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::STRING:
				{
					v1->valuetype = MagiLang::token::STRING;
					switch (v2->valuetype)
					{
					case MagiLang::token::STRING:
					{
						*((std::string*)outpt->value) = *((std::string*)v1->value) + *((std::string*)v2->value);
					}
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::BOOL:
				{
					v1->valuetype = MagiLang::token::BOOL;
					mglError("Incompatible types", v1->location);
				}
				break;
				default:
					break;

			}
		}
		else if (oprtr == "-")
		{
			switch (v1->valuetype)
			{
				case MagiLang::token::NUMBER:
				{
					v1->valuetype = MagiLang::token::NUMBER;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long long*)outpt->value) = *((long long*)v1->value) - *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long long*)outpt->value) = *((long long*)v1->value) - *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;

					}
				}
				break;
				case MagiLang::token::DECIMAL:
				{
					v1->valuetype = MagiLang::token::DECIMAL;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) - *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) - *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::STRING:
				{
					v1->valuetype = MagiLang::token::STRING;
					mglError("Incompatible types", v1->location);
				}
				break;
				case MagiLang::token::BOOL:
				{
					v1->valuetype = MagiLang::token::BOOL;
					mglError("Incompatible types", v1->location);
				}
				break;
				default:
					break;

			}
		}
		else if (oprtr == "*")
		{
			switch (v1->valuetype)
			{
				case MagiLang::token::NUMBER:
				{
					v1->valuetype = MagiLang::token::NUMBER;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long long*)outpt->value) = *((long long*)v1->value) * *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long long*)outpt->value) = std::round(*((long long*)v1->value) * *((long double*)v2->value));
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;

					}
				}
				break;
				case MagiLang::token::DECIMAL:
				{
					v1->valuetype = MagiLang::token::DECIMAL;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::STRING:
				{
					v1->valuetype = MagiLang::token::STRING;
					switch (v2->valuetype)
					{
					case MagiLang::token::STRING:
					{
						*((std::string*)outpt->value) = *((std::string*)v1->value) + *((std::string*)v2->value);
					}
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::BOOL:
				{
					v1->valuetype = MagiLang::token::BOOL;
					mglError("Incompatible types", v1->location);
				}
				break;
				default:
					break;

			}
		}
		else if (oprtr == "/")
		{
			switch (v1->valuetype)
			{
				case MagiLang::token::NUMBER:
				{
					v1->valuetype = MagiLang::token::NUMBER;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long long*)outpt->value) = std::round(*((long long*)v1->value) / *((long long*)v2->value));
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long long*)outpt->value) = std::round(*((long long*)v1->value) / *((long double*)v2->value));
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;

					}
				}
				break;
				case MagiLang::token::DECIMAL:
				{
					v1->valuetype = MagiLang::token::DECIMAL;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::STRING:
				{
					v1->valuetype = MagiLang::token::STRING;
					switch (v2->valuetype)
					{
					case MagiLang::token::STRING:
					{
						*((std::string*)outpt->value) = *((std::string*)v1->value) + *((std::string*)v2->value);
					}
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::BOOL:
				{
					v1->valuetype = MagiLang::token::BOOL;
					mglError("Incompatible types", v1->location);
				}
				break;
				default:
					break;

			}
		}
		else if (oprtr == "^")
		{
			switch (v1->valuetype)
			{
				case MagiLang::token::NUMBER:
				{
					v1->valuetype = MagiLang::token::NUMBER;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long long*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long long*)outpt->value) = std::round(*((long long*)v1->value) + *((long double*)v2->value));
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;

					}
				}
				break;
				case MagiLang::token::DECIMAL:
				{
					v1->valuetype = MagiLang::token::DECIMAL;
					switch (v2->valuetype)
					{
					case MagiLang::token::NUMBER:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long long*)v2->value);
					}
					break;
					case MagiLang::token::DECIMAL:
					{
						*((long double*)outpt->value) = *((long long*)v1->value) + *((long double*)v2->value);
					}
					break;
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::STRING:
				{
					v1->valuetype = MagiLang::token::STRING;
					switch (v2->valuetype)
					{
					case MagiLang::token::STRING:
					{
						*((std::string*)outpt->value) = *((std::string*)v1->value) + *((std::string*)v2->value);
					}
					default:
						mglError("Incompatible types", v1->location);
						break;
					}
				}
				break;
				case MagiLang::token::BOOL:
				{
					v1->valuetype = MagiLang::token::BOOL;
					mglError("Incompatible types", v1->location);
				}
				break;
				default:
					break;

			}
		}*/
	}
}