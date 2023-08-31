#pragma once


//class MyData {
//public:
//	enum class MyFormat {
//		kText,
//		kHTML,
//		kJSON
//	};
//
//	MyData(const std::string data) : m_data(data) {}
//
//	MyFormat SetNextFormat(MyFormat nextFormat) noexcept {
//		mp_nextFormat = nextFormat;
//		return mp_nextFormat;
//	}
//
//	virtual std::string print(MyFormat format = MyFormat::kText) noexcept {
//		MyData::print(mp_nextFormat);
//		return {};
//	}
//
//protected:
//	std::string m_data;
//
//private:
//	MyFormat mp_nextFormat = MyFormat::kText;
//};
//
//class Text_String : public MyData {
//public:
//	std::string print(MyFormat format) override {
//		if (m_format == MyFormat::kText) {
//			return m_data;
//		}
//		MyData::SetNextFormat(MyFormat::kHTML);
//		return MyData::print();
//	}
//
//private:
//	MyFormat m_format = MyFormat::kText;
//};
//
//class HTML_String : public MyData {
//public:
//	std::string print(MyFormat format) override {
//		if (m_format == MyFormat::kHTML) {
//			return m_data;
//		}
//		MyData::SetNextFormat(MyFormat::kJSON);
//		return MyData::print();
//	}
//
//private:
//	MyFormat m_format = MyFormat::kHTML;
//};
//
//class JSON_String : public MyData {
//public:
//	std::string print(MyFormat format) override {
//		if (m_format == MyFormat::kJSON) {
//			return m_data;
//		}
//		MyData::SetNextFormat(MyFormat::kText);
//		return MyData::print();
//	}
//
//private:
//	MyFormat m_format = MyFormat::kJSON;
//};


enum class MyFormat {
	kText,
	kHTML,
	kJSON
};

class MyData {
public:
	virtual std::string print(MyFormat format = MyFormat::kText) const noexcept {
		return "Ошибка формата!";
	};

	virtual ~MyData() = default;

protected:
	std::string m_data;
};

//class DefaultHandler : public Handler {
//public:
//	bool print(int request) override {
//		printf("%d is prime\n", request);
//		return false;
//	}
//};

class Text : public MyData {
public:
	explicit Text(const std::string& data) {
		m_data = data;
	}

	std::string print(MyFormat format) const noexcept override {
		if (format == MyFormat::kText)
			return m_data;
		else
			return MyData::print(format);
	}
};

class HTML : public MyData {
public:
	explicit HTML(const std::string& data) {
		m_data = data;
	}

	std::string print(MyFormat format) const noexcept override {
		if (format == MyFormat::kHTML)
			return "<html>" + m_data + "<html/>";
		else
			return MyData::print(format);
	}
};

class JSON : public MyData {
public:
	explicit JSON(const std::string& data) {
		m_data = data;
	}

	std::string print(MyFormat format) const noexcept override {
		if (format == MyFormat::kJSON)
			return "{ \"data\": \"" + m_data + "\"}";
		else
			return MyData::print(format);
	}
};
