#include<iostream>
#include<memory>

class Data {
	public:
	virtual void sendData()=0;
};

class Udp : public Data{
	public:
		void sendData(){std::cout<<"sending data through udp";}
};

class Terminal : public Data{
	public :
		void sendData(){std::cout<< "sending data over Terminal";}

};

class DIntrfc{
	public:
	static DIntrfc*instance(){
	static DIntrfc di;
	return &di;
	
	}

	std::shared_ptr<Data> create_data(const std::string type){
		if(type == "udp") return std::make_shared<Udp>();
		else if(type == "terminal") return std::make_shared<Terminal>();
		else return nullptr;
	
	}
};

int main(){

	std::shared_ptr<Data> data = DIntrfc::instance()->create_data("udp");
	//Data *data = new Udp(); if Udp is passed
	if(data == nullptr){std::cout<<"provide valid data"; return 1;}
	data->sendData();
	return 0;
}
