// 编译不过 仅是记录
namespace reflect
{
	template<typename B, typename... Targs>
		class ClassFactory
		{
			public:
				static ClassFactory* Instance() {  
					std::cout << "static ClassFactory* Instance()" << std::endl;  
					if (nullptr == factory_) {  
						factory_ = new ClassFactory();  
					}  
					return(factory_);  
				}  
				virtual ~ClassFactory(){};  

				bool Regist(const std::string& strTypeName, std::function<B *(Targs&&... args) pFunc>)
				{
					if(nullptr == pFunc)
						return false;
					std::string strRealTypeName = strTypeName;
					bool bReg = creator_map 
				}
				B* Create(const std::string& strTypeName, Targs&& agrs)
				{
					auto iter = creator_map_.find(strTypeName);
					if(iter == creator_map_.end())
						return nullptr;
					return (iter->second(std::forward<Targs>(args)...));
				}

			private:
				ClassFactory(){std::cout << "ClassFactory construct" << std::endl;};
				static ClassFactory<B, Targs...>* factory_;
				std::unordered_map<std::string, std::function<B*(Targs&&...)>> creator_map_;
		};
	template<typename B, typename ...Targs>
		ClassFactory<B, Targs...>* ClassFactory<B, Targs...>::factory_ = nullptr;

	// 动态对象创建器，B必须是T的基类，B用于返回指针引用
	template<typename B, typename T, typename ...Targs>
		class DynamicCreator
		{
			public:
				struct Register
				{
					Register()
					{
						char* szDemangleName = nullptr;
						std::string strTypeName;
						szDemangleName = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
						if(szDemangleName != nullptr)
						{
							strTypeName = szDemangleName;
							free(szDemangleName);
						}
						ClassFactory<B, Targs...>::Instance()->Regist(strTypeName, CreateObject);
					}
				}
				inline void do_nothing() const {};
				DynamicCreator()
				{
					s_registor.do_nothing();
				}
				virtual ~DynamicCreator(){ s_registor.do_nothing(); }
				static B* CreateObject(Targs&&... args)
				{
					return new T(std::forward<Targs>(args)...);
				}
				virtual void Say()
				{
					std::cout << "DynamicCreator say" << std::endl;
				}
			private:
				static Register s_registor;
		};

	class A
	{
		public:
			virtual void Say() = 0;
			virtual ~A(){}

	};

	class B : public A, public DynamicCreator<A, B>
	{
		public:
			B() { //xxx }
			virtual void Say()
			{
				// xxx
			}
	};

	class C : public A, public DynamicCreator<A,C,int>
	{
		public:
			C(int x)
			{
				// xxx
			}

	};
}
