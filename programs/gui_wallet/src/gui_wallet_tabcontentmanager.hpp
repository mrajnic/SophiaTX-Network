/* (c) 2016, 2017 DECENT Services. For details refers to LICENSE.txt */
#pragma once

#include <QWidget>
#include <string>
#include <vector>

namespace gui_wallet {

class TabContentManager : public QWidget
{
public:
   TabContentManager(QWidget* pParent);

   virtual void timeToUpdate(const std::string& result) = 0;
   virtual std::string getUpdateCommand() = 0;
   
public:
   void tryToUpdate();

   bool next();
   void reset(bool bRefresh = true);
   bool previous();
   bool is_first() const;
   bool is_last() const;
   void set_next_page_iterator(std::string const& iterator);
   std::string next_iterator() const;
   size_t m_i_page_size;
   
private:
   std::string m_last_result;
   std::string m_next_iterator;
   std::vector<std::string> m_iterators;
};

   
}

