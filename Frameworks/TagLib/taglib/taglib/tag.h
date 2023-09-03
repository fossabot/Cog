/***************************************************************************
    copyright            : (C) 2002 - 2008 by Scott Wheeler
    email                : wheeler@kde.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_TAG_H
#define TAGLIB_TAG_H

#include <taglib/taglib_export.h>
#include <taglib/toolkit/tstring.h>

namespace TagLib {

  //! A simple, generic interface to common audio meta data fields

  /*!
   * This is an attempt to abstract away the difference in the meta data formats
   * of various audio codecs and tagging schemes.  As such it is generally a
   * subset of what is available in the specific formats but should be suitable
   * for most applications.  This is meant to compliment the generic APIs found
   * in TagLib::AudioProperties, TagLib::File and TagLib::FileRef.
   */

  class PropertyMap;

  class TAGLIB_EXPORT Tag
  {
  public:

    /*!
     * Destroys this Tag instance.
     */
    virtual ~Tag();

    /*!
     * Exports the tags of the file as dictionary mapping (human readable) tag
     * names (Strings) to StringLists of tag values.
     * The default implementation in this class considers only the usual built-in
     * tags (artist, album, ...) and only one value per key.
     */
    PropertyMap properties() const;

    /*!
     * Removes unsupported properties, or a subset of them, from the tag.
     * The parameter \a properties must contain only entries from
     * properties().unsupportedData().
     * BIC: Will become virtual in future releases. Currently the non-virtual
     * standard implementation of TagLib::Tag does nothing, since there are
     * no unsupported elements.
     */
    void removeUnsupportedProperties(const StringList& properties);

    /*!
     * Sets the tags of this File to those specified in \a properties. This default
     * implementation sets only the tags for which setter methods exist in this class
     * (artist, album, ...), and only one value per key; the rest will be contained
     * in the returned PropertyMap.
     */
    PropertyMap setProperties(const PropertyMap &properties);

    /*!
     * Returns the track name; if no track name is present in the tag
     * String::null will be returned.
     */
    virtual String title() const = 0;

    /*!
     * Returns the album artist name; if no artist name is present in the tag
     * String::null will be returned.
     */
    virtual String albumartist() const = 0;

    /*!
     * Returns the artist name; if no artist name is present in the tag
     * String::null will be returned.
     */
    virtual String artist() const = 0;

    /*!
     * Returns the composer name; if no composer name is present in the tag
     * String::null will be returned.
     */
    virtual String composer() const = 0;

    /*!
     * Returns the album name; if no album name is present in the tag
     * String::null will be returned.
     */
    virtual String album() const = 0;

    /*!
     * Returns the unsynced lyrics; if no unsynced lyrics are present
     * in the tag String::null will be returned.
     */
    virtual String unsyncedlyrics() const = 0;

    /*!
     * Returns the track comment; if no comment is present in the tag
     * String::null will be returned.
     */
    virtual String comment() const = 0;

    /*!
     * Returns the genre name; if no genre is present in the tag String::null
     * will be returned.
     */
    virtual String genre() const = 0;

    /*!
     * Returns the year; if there is no year set, this will return 0.
     */
    virtual unsigned int year() const = 0;

    /*!
     * Returns the track number; if there is no track number set, this will
     * return 0.
     */
    virtual unsigned int track() const = 0;

    /*!
     * Returns the disc number; if there is no track number set, this will
     * return 0.
     */
    virtual unsigned int disc() const = 0;

    /*!
     * Returns the embedded cuesheet; if there is no cuesheet set, this
     * will return an empty string.
     */
    virtual String cuesheet() const = 0;

    /*!
    * Returns the ReplayGain album gain; if there is no gain level set, this
    * will return 0.
    */
    virtual float rgAlbumGain() const = 0;

    /*!
    * Returns the ReplayGain album peak; if there is no gain level set, this
    * will return 0.
    */
    virtual float rgAlbumPeak() const = 0;

    /*!
    * Returns the ReplayGain track gain; if there is no gain level set, this
    * will return 0.
    */
    virtual float rgTrackGain() const = 0;

    /*!
    * Returns the ReplayGain track peak; if there is no gain level set, this
    * will return 0.
    */
    virtual float rgTrackPeak() const = 0;

    /*!
     * Returns the Apple SoundCheck tag; if there is tag set, this will
     * return empty.
     */
    virtual String soundcheck() const = 0;

    /*!
     * Sets the title to \a s.  If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setTitle(const String &s) = 0;

    /*!
     * Sets the album artist to \a s.  If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setAlbumArtist(const String &s) = 0;

    /*!
     * Sets the artist to \a s.  If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setArtist(const String &s) = 0;

    /*!
     * Sets the composer to \a s. If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setComposer(const String &s) = 0;

    /*!
     * Sets the album to \a s.  If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setAlbum(const String &s) = 0;

    /*!
     * Sets the unsynced lyrics to \a s. If \a s is String::null then this
     * value will be cleared.
     */
    virtual void setUnsyncedlyrics(const String &s) = 0;

    /*!
     * Sets the comment to \a s.  If \a s is String::null then this value will be
     * cleared.
     */
    virtual void setComment(const String &s) = 0;

    /*!
     * Sets the genre to \a s.  If \a s is String::null then this value will be
     * cleared.  For tag formats that use a fixed set of genres, the appropriate
     * value will be selected based on a string comparison.  A list of available
     * genres for those formats should be available in that type's
     * implementation.
     */
    virtual void setGenre(const String &s) = 0;

    /*!
     * Sets the year to \a i.  If \a s is 0 then this value will be cleared.
     */
    virtual void setYear(unsigned int i) = 0;

    /*!
     * Sets the track to \a i.  If \a s is 0 then this value will be cleared.
     */
    virtual void setTrack(unsigned int i) = 0;

    /*!
     * Sets the disc to \a i.  If \a s is 0 then this value will be cleared.
     */
    virtual void setDisc(unsigned int i) = 0;

    /*!
     * Sets the embedded cuesheet to \a s. If \a s is empty then this
     * value will be cleared.
     */
    virtual void setCuesheet(const String &s) = 0;

    /*!
    * Sets the ReplayGain album gain to \a f. If \a f is 0 then this value will
    * be cleared.
    */
    virtual void setRGAlbumGain(float i) = 0;

    /*!
    * Sets the ReplayGain album peak to \a f. If \a f is 0 then this value will
    * be cleared.
    */
    virtual void setRGAlbumPeak(float i) = 0;

    /*!
    * Sets the ReplayGain track gain to \a f. If \a f is 0 then this value will
    * be cleared.
    */
    virtual void setRGTrackGain(float i) = 0;

    /*!
    * Sets the ReplayGain track peak to \a f. If \a f is 0 then this value will
    * be cleared.
    */
    virtual void setRGTrackPeak(float i) = 0;

    /*!
     * Returns true if the tag does not contain any data.  This should be
     * reimplemented in subclasses that provide more than the basic tagging
     * abilities in this class.
     */
    virtual bool isEmpty() const;

    /*!
     * Copies the generic data from one tag to another.
     *
     * \note This will no affect any of the lower level details of the tag.  For
     * instance if any of the tag type specific data (maybe a URL for a band) is
     * set, this will not modify or copy that.  This just copies using the API
     * in this class.
     *
     * If \a overwrite is true then the values will be unconditionally copied.
     * If false only empty values will be overwritten.
     */
    static void duplicate(const Tag *source, Tag *target, bool overwrite = true);

  protected:
    /*!
     * Construct a Tag.  This is protected since tags should only be instantiated
     * through subclasses.
     */
    Tag();

  private:
    Tag(const Tag &);
    Tag &operator=(const Tag &);

    class TagPrivate;
    TagPrivate *d;
  };
}

#endif
