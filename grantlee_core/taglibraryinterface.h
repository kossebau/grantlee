/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 3 only, as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License version 3 for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef TAGLIBRARYINTERFACE_H
#define TAGLIBRARYINTERFACE_H

#include <QtCore/QHash>

namespace Grantlee
{
class AbstractNodeFactory;
class Filter;

/**
  @brief The TagLibraryInterface returns available tags and filters from libraries.

  This interface must be implemented in tag and filter libraries.

  The implementation will usually be very simple.

  @code
    class MyTagLibrary : public QObject, public TagLibraryInterface
    {
      Q_OBJECT
      Q_INTERFACES( Grantlee::TagLibraryInterface )
    public:
      MyTagLibrary( QObject *parent = 0 )
          : QObject( parent ) {
      }

      QHash<QString, AbstractNodeFactory*> nodeFactories( const QString &name = QString() ) {
        Q_UNUSED( name );
        QHash<QString, AbstractNodeFactory*> nodeFactories;
        nodeFactories.insert( "mytag1", new MyTag1() );
        nodeFactories.insert( "mytag2", new MyTag2() );
        return nodeFactories;
      }

      QHash<QString, Filter*> filters( const QString &name = QString() ) {
        Q_UNUSED( name );

        QHash<QString, Filter*> filters;

        filters.insert( "myfilter1", new MyFilter1() );
        filters.insert( "myfilter2", new MyFilter2() );

        return filters;
      }
    };
  @endcode
*/
class TagLibraryInterface
{
public:
  virtual ~TagLibraryInterface() {}

  virtual QHash<QString, AbstractNodeFactory*> nodeFactories( const QString &name = QString() ) {
    Q_UNUSED( name );
    QHash<QString, AbstractNodeFactory*> h;
    return h;
  };

  virtual QHash<QString, Filter*> filters( const QString &name = QString() ) {
    Q_UNUSED( name );
    QHash<QString, Filter*> h;
    return h;
  };
};

}

Q_DECLARE_INTERFACE( Grantlee::TagLibraryInterface, "org.kde.grantlee.TagLibraryInterface/1.0" )

#endif
